/*
** event_internal.c for Zappy in ./server_zappy/src
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
#include	<stdio.h>

#include	"error.h"
#include	"event.h"
#include	"tserver.h"

static bool	match_event(void *elem, void *arg)
{
  t_event	*e;
  t_catch	*c;

  if (!(c = elem) || !(e = arg) ||
      !c->name || !e->name)
    return (false);
  if ((strcasecmp(c->name, e->name) == 0))
    return (true);
  return (false);
}

static bool	event_catch_dispatch(t_catch *catcher, t_event *event)
{
  if (!catcher || !event || !catcher->call)
    return (false);
  return (catcher->call(event->data));
}

bool		eventm_dispatch(t_event *event)
{
  t_catch	*catchers;

  print_debug("Event [%s] Dispatched", event->name);
  if (!event || !event->name ||
      !(catchers = get_data_as_arg(get_catchers(), match_event, event)))
    {
      if (event->free)
	free(event->data);
      if (event->name)
	free(event->name);
      return (true);
    }
  foreach_arg_list(catchers->catch,
		   (void(*)(void*, void*))event_catch_dispatch, event);
  event_catch_dispatch(catchers, event);
  if (event->free)
    free(event->data);
  if (event->name)
    free(event->name);
  return (true);
}
