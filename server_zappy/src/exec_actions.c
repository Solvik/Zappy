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

#include	"error.h"
#include	"module.h"
#include	"client.h"
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
  t_client	*info;
  t_module	*module;
  t_mod_func	*functions;

  if (!client || !s || !(info = client->trick) ||
      !(module = info->_m))
    return (false);
  functions = module->functions;
  while (functions && (*functions).action)
    {
      if (parse_cmp(s, (*functions).command) && (*functions).action)
	return ((*functions).action(client, s));
      functions = &functions[1];
    }
  return (false);
}

bool		exec_actions(fds pool, double tdt)
{
  (void)	tdt;
  char		*s;

  while (pool)
    {
      if (pool->type != SERV)
	{
	  s = getcmd(pool);
	  if (!(pool->trick) ||
	      !(((t_client*)pool->trick)->_m))
	    {
	      mod_discovery(pool, s);
	      free(s);
	    }
	  else if (s && (s = flood_check(pool, s)))
	    if ((int)find_action(pool, s) != -1)
	      flood_read(pool);
	}
      pool = pool->next;
    }
  return (true);
}
