/*
** exec_actions.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Jun 28 21:28:27 2011 julien di-marco
** Last update Tue Jun 28 21:28:27 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"error.h"
#include	"module.h"
#include	"client.h"
#include	"scheduler.h"
#include	"callback.h"
#include	"run.h"
#include	"tserver.h"

extern t_server	*gserv;

bool		parse_cmp(char *c, char *m)
{
  char		*help;

  help = NULL;
  if (!c || !m)
    return (false);
  if (strncasecmp(c, m, strlen(m)) == 0)
    if ((strlen(c) == strlen(m)) || c[strlen(m)] == ' ')
      return (true);
  return (false);
}

bool		find_action(fds client, char *s)
{
  bool		(*schedule)(fds, _time, bool (*)(fds, char*), void *);
  t_client	*info;
  t_module	*module;
  t_mod_func	*functions;

  if (!client || !s || !(info = client->trick) ||
      !(module = info->_m) || !(functions = module->functions))
    return (false);
  while (functions && (*functions).action)
    {
      if (parse_cmp(s, (*functions).command) && (*functions).action)
	{
	  schedule = (void*)((*functions).relative ?
		      scheduler_relative : scheduler_action);
	  if ((*functions).delay <= 0.0)
	    return ((*functions).action(client, s));
	  else
	    schedule(client, (*functions).delay, (*functions).action, s);
	  scheduler_free(client);
	  return ((bool)-1);
	}
      functions = &functions[1];
    }
  return (false);
}

bool		exec_client(fds c, double tdt)
{
  char		*s;

  s = getcmd(c);
  if (!(c->trick) || !(((t_client*)c->trick)->_m))
    return (mod_discovery(c, &s));
  s = flood_check(c, s);
  if (scheduler_(c, tdt))
    return (scheduler_dispatch(c));
  else if (callback_(c, s, tdt))
    return (callback_handler(c, s));
  else if (s && !scheduler_active(c) && (int)find_action(c, s) != -1)
    flood_read(c);
  return (true);
}

bool		exec_pool(fds pool, double tdt)
{
  (void)	tdt;

  while (pool)
    {
      if (pool->type != SERV)
	exec_client(pool, tdt);
      pool = pool->next;
    }
  return (true);
}
