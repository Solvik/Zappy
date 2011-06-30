/*
** server_zappy/init.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:01 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:01 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<signal.h>
#include	<stdio.h>

#include	"map.h"
#include	"zopt.h"
#include	"init.h"
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server	*gserv;

void		sigint_handler(int _)
{
  (void)_;
  gserv->run = false;
  write(STDOUT_FILENO, "\b\b", 2);
}

bool		init(int opt_size, char **opt)
{
  t_zopt	optab;

  gserv_const(true);
  if ((signal(SIGINT, sigint_handler) == SIG_ERR) ||
      !init_opt(opt_size, opt, &optab) ||
      !init_map(&optab) ||
      !init_network(&optab) ||
      !init_modules(&optab))
    return (false);
  set_delay(optab.delay);
  set_time(optab.time);
  printf("d: %f - t: %f\n", optab.delay, optab.time);
  return ((gserv->run = true));
}
