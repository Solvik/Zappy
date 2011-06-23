
#include	<strings.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"dbg.h"
#include	"run.h"
#include	"module.h"
#include	"client.h"
#include	"tserver.h"
#include	"net.h"
#include	"server_zappy.h"

extern t_server	*gserv;

static bool	module_handskaking(void *elem, void *arg)
{
  t_module	*module;
  fds		client;

  if (!(module = elem) || !(client = arg) || !client->trick)
    return (true);
  if ((int)module->port != client->port)
    return (false);
  if (module->handshaking &&
      module->handshaking(client, ((t_client*)client->trick)->command))
    {
      printf("Congrat to them - they just share a beer !\n");
      ((t_client*)client->trick)->_m = module;
      put_in_list(&module->clients, client);
      if ((int)module->antiflood > 0)
	{
	  ((t_client*)client->trick)->flood.array = \
	    calloc(module->antiflood  + 1, sizeof(char*));
	  ((t_client*)client->trick)->flood.size = module->antiflood;
	}
      return (true);
    }
  return (false);
}

bool		discover_module(fds client, char *cmd)
{
  t_client	*info;

  if (!client)
    return (false);
  if (!(info = client->trick))
    {
      if (!(client->trick = calloc(1, sizeof(*info))))
	return (false);
      else
	info = client->trick;
    }
  ((t_client*)client->trick)->command = cmd;
  foreach_arg_stop_list(get_modules(), module_handskaking, client);
  ((t_client*)client->trick)->command = NULL;
  return (true);
}

char		*flood_check(fds pool, char *s)
{
  t_antiflood	*flood;
  t_client	*info;

  if (!pool || !(info = pool->trick) ||
      !(flood = &info->flood) || !s ||
      !(flood->size <= 0 || flood->array))
    return (NULL);
  if (flood->size <= 0 && info->command)
    free(s);
  if (flood->size <= 0 && !info->command)
      return ((info->command = s));
  if (flood->write == flood->read)
    memset(&flood->read, 0, sizeof(flood->read) * 2);
  if ((flood->write - flood->read) < flood->size)
    flood->array[(flood->write++) % flood->size] = s;
  else
    free(s);
  if ((flood->write - flood->read) > 0)
    return (flood->array[(flood->read % flood->size)]);
  return (NULL);
}

bool		flood_read(fds pool)
{
  t_antiflood	*flood;
  t_client	*info;

  if (!pool || !(info = pool->trick) ||
      !(flood = &info->flood) ||
      !(flood->size <= 0 || flood->array))
    return (false);
  if (flood->size <= 0 && info->command)
    {
      free(info->command);
      info->command = NULL;
      return (true);
    }
  if (!((flood->write - flood->read) > 0))
    return (false);
  free(flood->array[(flood->read % flood->size)]);
  flood->array[((flood->read++) % flood->size)] = NULL;
  if (flood->write == flood->read && flood->write != 0)
    memset(&flood->read, 0, sizeof(flood->read) * 2);
  return (true);
}

bool		execute(fds	pool)
{
  char		*s;

  while (pool)
    {
      if (pool->type != SERV)
	{
	  s = getcmd(pool);
	  if (!(pool->trick) ||
	      !(((t_client*)pool->trick)->_m))
	    discover_module(pool, s);
	  else if (s && (s = flood_check(pool, s)))
	    printf("Call [%s]\n", s);
	  flood_read(pool);
	}
      pool = pool->next;
    }
  return (true);
}

bool		run(void)
{
  while (!run_end())
    {
      pool(&gserv->pool);
      execute(gserv->pool);
    }
  return (true);
}
