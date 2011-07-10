/*
** exec_timer.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include        <stdbool.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        <stdio.h>

#include        "time_.h"
#include        "scheduler.h"
#include        "event.h"
#include        "module.h"
#include        "tserver.h"

static void             module_timer(t_module *elem, double *arg)
{
  double        out;

  if (!elem || !arg)
    return ;
  if (!elem->timer)
    return ;
  *arg = (out = elem->timer()) < *arg || (*arg <= -1.0) ? out : *arg;
}

bool            exec_timer(time__ **tv, double tdt)
{
  static time__ *t = NULL;
  t_list        *modules;
  double        idle;
  double        time;

  idle = -1.0;
  if ((tv == (time__**)-1) && (tdt == -133742))
    {
      if (t)
        free(t);
      return (true);
    }
  if (!tv || (!t && !(t = calloc(1, sizeof(*t)))))
    return (false);
  if ((modules = get_modules()))
    foreach_arg_list(modules, (void(*)(void*, void*))module_timer, &idle);
  idle = (((time = scheduler_update(-1.0)) < idle) || idle <= -1.0) &&
    time > -1.0 ? time : idle;
  idle = (((time = event_update(-1.0)) < idle) || idle <= -1.0) &&
    time > -1.0 ? time : idle;
  *tv = timeval_(t, idle);
  return ((idle <= -1.0 ? (bool)(*tv = NULL) : true));
}
