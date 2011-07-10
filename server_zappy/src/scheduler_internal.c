/*
** scheduler_internal.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"client.h"
#include	"scheduler.h"
#include	"exec.h"

#include	"tserver.h"

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
  schedule->dt -= (schedule->relative ? (dt * get_delay()) / get_time() : dt);
  if ((schedule->dt <= 0.0))
    return (true);
  else
    scheduler_update((!schedule->relative ? schedule->dt :
		      (schedule->dt * (get_time() / get_delay()))));
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
  if ((schedule->free))
    flood_read(c);
  schedule->data = NULL;
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

bool		scheduler_destroy(t_client *c)
{
  t_scheduler	*schedule;

  if (!c || !(schedule = &c->schedule))
    return (false);
  return (true);
}
