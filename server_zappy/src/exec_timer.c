/*
** exec_timer.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 29 01:07:29 2011 julien di-marco
** Last update Wed Jun 29 01:07:29 2011 julien di-marco
*/

#include	<stdbool.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"time_.h"
#include	"scheduler.h"
#include	"module.h"
#include	"tserver.h"

/*   *tv = timeval_(t, (lol = (scheduler_update(-1.0)))); */
/*   if (lol <= -1.0) */
/*     *tv = NULL; */

static void		module_timer(t_module *elem, double *arg)
{
  double	out;

  if (!elem || !arg)
    return ;
  if (!elem->timer)
    return ;
  *arg = (out = elem->timer()) < *arg ? out : *arg;
}

bool		exec_timer(time__ **tv, double tdt)
{
  static time__	*t = NULL;
  t_list	*modules;
  double	idle;
  double	time;

  (void)tdt;
  idle = -1.0;
  if (!tv || (!t && !(t = calloc(1, sizeof(*t)))))
    return (false);
  if ((modules = get_modules()))
    foreach_arg_list(modules, (void(*)(void*, void*))module_timer, &idle);
  idle = (time = scheduler_update(-1.0)) < idle && time > -1.0 ? time : idle;
  *tv = timeval_(t, idle);
  return ((idle <= -1.0 ? (bool)(*tv = NULL) : true));
}
