
#include	<unistd.h>
#include	<stdlib.h>
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
      module->handshaking(client, ((t_client*)client->trick)->antiflood))
    {
      printf("Congrat to them - they just share a beer !\n");
      ((t_client*)client->trick)->_m = module;
      put_in_list(&module->clients, client);
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
  ((t_client*)client->trick)->antiflood = cmd;
  foreach_arg_stop_list(get_modules(), module_handskaking, client);
  ((t_client*)client->trick)->antiflood = NULL;
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
	  free(s);
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
