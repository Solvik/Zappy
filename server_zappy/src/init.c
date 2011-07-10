/*
** init.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#undef		_FORTIFY_SOURCE

#include	<unistd.h>
#include	<stdlib.h>
#include	<signal.h>
#include	<stdio.h>

#include	"map.h"
#include	"zopt.h"
#include	"init.h"
#include	"tserver.h"
#include	"server_zappy.h"

void		sigint_handler(__attribute__((unused))int _)
{
  set_run(false);
  write(STDOUT_FILENO, "\b\b", 2);
}

static bool	check_network(void)
{
  fds		*pool;
  fds		tmp;
  bool		out;

  out = false;
  if (!(pool = get_pool()) || !(tmp = *pool))
    return ((out = false));
  while (tmp)
    {
      if (fds_alive(tmp))
	out = true;
      tmp = tmp->next;
    }
  return (out);
}

bool		init(int opt_size, char **opt)
{
  t_zopt	optab;
  bool		out;

  out = true;
  gserv_const(true);
  if ((signal(SIGINT, sigint_handler) == SIG_ERR) ||
      !init_opt(opt_size, opt, &optab) ||
      !init_random(&optab) ||
      !init_map(&optab) ||
      !init_network(&optab) ||
      !init_team(&optab) ||
      !init_modules(&optab) ||
      !check_network())
    out = false;
  destroy_list(&optab.team, free);
  destroy_list(&optab.module, free);
  set_run((out));
  return (out);
}
