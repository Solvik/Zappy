/*
** exec_event.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Mon Jul  4 23:32:24 2011 Julien Di Marco
** Last update Mon Jul  4 23:32:24 2011 Julien Di Marco
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

