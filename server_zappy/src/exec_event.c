/*
** exec_event.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"time_.h"
#include	"event.h"
#include	"tserver.h"

double		event_update(double r)
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

static bool	event_check(t_event *elem, double *_)
{
  double	dt;

  (void)_;
  if (!elem || !_)
    return (false);
  dt = time_d(elem->lt);
  elem->lt = time_();
  elem->delay -= (elem->relative ? (dt * get_delay()) / get_time() : dt);
  if ((elem->delay <= 0.0))
    return (eventm_dispatch(elem));
  else
    event_update((!elem->relative ? elem->delay :
		  (elem->delay * (get_time() / get_delay()))));
  return (false);
}

bool		exec_event(double tdt)
{
  t_list	**event;

  if (!(event = singleton_event()))
    return (false);
  del_all_node_as_arg(event, (bool(*)(void*, void*))event_check, free, &tdt);
  return (true);
}

