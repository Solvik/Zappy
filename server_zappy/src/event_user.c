/*
** event_user.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Mon Jul  4 16:37:38 2011 Julien Di Marco
** Last update Mon Jul  4 16:37:38 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"time_.h"
#include	"event.h"
#include	"tserver.h"

extern t_server	*gserv;

bool		event_dispatch(char *name, void *data, double delay)
{
  t_event	*to_dispatch;

  if (!name || !(to_dispatch = calloc(1, sizeof(*to_dispatch))))
    return (false);
  to_dispatch->name = strdup(name);
  to_dispatch->data = data;
  to_dispatch->delay = delay;
  to_dispatch->st = time_();
  to_dispatch->lt = to_dispatch->st;
  return (set_new_event(to_dispatch));
}

bool		event_free(char *name, void *data, double delay)
{
  t_event	*to_dispatch;

  if (!name || !(to_dispatch = calloc(1, sizeof(*to_dispatch))))
    return (false);
  to_dispatch->name = strdup(name);
  to_dispatch->data = data;
  to_dispatch->delay = delay;
  to_dispatch->free = true;
  to_dispatch->st = time_();
  to_dispatch->lt = to_dispatch->st;
  return (set_new_event(to_dispatch));
}

bool		event_relative_dispatch(char *name, void *data, double delay)
{
  t_event	*to_dispatch;

  if (!name || !(to_dispatch = calloc(1, sizeof(*to_dispatch))))
    return (false);
  to_dispatch->name = strdup(name);
  to_dispatch->data = data;
  to_dispatch->delay = delay;
  to_dispatch->relative = true;
  to_dispatch->st = time_();
  to_dispatch->lt = to_dispatch->st;
  return (set_new_event(to_dispatch));
}

bool		event_free_relative(char *name, void *data, double delay)
{
  t_event	*to_dispatch;

  if (!name || !(to_dispatch = calloc(1, sizeof(*to_dispatch))))
    return (false);
  to_dispatch->name = strdup(name);
  to_dispatch->data = data;
  to_dispatch->delay = delay;
  to_dispatch->free = true;
  to_dispatch->relative = true;
  to_dispatch->st = time_();
  to_dispatch->lt = to_dispatch->st;
  return (set_new_event(to_dispatch));
}

bool		event_catch(char *name, bool (*call)(void*))
{
  t_catch	*catcher;
  if (!name || !call ||
      !(catcher = calloc(1, sizeof(*catcher))))
    return (false);
  catcher->name = strdup(name);
  catcher->call = call;
  return (set_new_catcher(catcher));
}
