/*
** scheduler_internal.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 29 17:43:22 2011 julien di-marco
** Last update Wed Jun 29 17:43:22 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"client.h"
#include	"scheduler.h"
#include	"exec.h"

bool		scheduler_(fds c, double tdt)
{
  (void)tdt;
  double	dt;
  t_client	*info;
  t_scheduler	*schedule;

  if (!scheduler_active(c) || !c || !(info = c->trick))
    return (false);
  schedule = &info->schedule;
  dt = time_d(schedule->lt);
  schedule->lt = time_();
  schedule->dt -= dt;
  if ((schedule->dt <= 0.0))
    return (true);
  else
    scheduler_update(schedule->dt);
  return (false);
}

bool		scheduler_dispatch(fds c)
{
  _time		t;
  t_client	*info;
  t_scheduler	*schedule;
  bool		out;

  t = time_();
  out = false;
  if (!c || !(info = c->trick))
    return (out);
  schedule = &info->schedule;
  if (!schedule->callback)
    return (out);
  if (schedule->callback(c, schedule->data))
    out = true;
  schedule->callback = NULL;
  schedule->state = (char)false;
  return (exec_client(c, time_d(t)));
}

double		scheduler_update(double r)
{
  static double	dt = -1.0;
  double	o;

  if ((r == -1.0))
    {
      o = dt;
      dt = -1.0;
      return (o);
    }
  return ((dt = (r < dt || dt < 0.0 ? r : dt)));
}
