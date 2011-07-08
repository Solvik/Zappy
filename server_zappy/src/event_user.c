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
  t_event	*evnt;

  if (!name || !(evnt = calloc(1, sizeof(*evnt))))
    return (false);
  evnt->name = strdup(name);
  evnt->data = data;
  evnt->delay = delay;
  evnt->st = time_();
  evnt->lt = evnt->st;
  return (delay > 0.0 ? set_new_event(evnt) : eventm_dispatch(evnt));
}

bool		event_free(char *name, void *data, double delay)
{
  t_event	*evnt;

  if (!name || !(evnt = calloc(1, sizeof(*evnt))))
    return (false);
  evnt->name = strdup(name);
  evnt->data = data;
  evnt->delay = delay;
  evnt->free = true;
  evnt->st = time_();
  evnt->lt = evnt->st;
  return (delay > 0.0 ? set_new_event(evnt) : eventm_dispatch(evnt));
}

bool		event_relative_dispatch(char *name, void *data, double delay)
{
  t_event	*evnt;

  if (!name || !(evnt = calloc(1, sizeof(*evnt))))
    return (false);
  evnt->name = strdup(name);
  evnt->data = data;
  evnt->delay = delay;
  evnt->relative = true;
  evnt->st = time_();
  evnt->lt = evnt->st;
  return (delay > 0.0 ? set_new_event(evnt) : eventm_dispatch(evnt));
}

bool		event_free_relative(char *name, void *data, double delay)
{
  t_event	*evnt;

  if (!name || !(evnt = calloc(1, sizeof(*evnt))))
    return (false);
  evnt->name = strdup(name);
  evnt->data = data;
  evnt->delay = delay;
  evnt->free = true;
  evnt->relative = true;
  evnt->st = time_();
  evnt->lt = evnt->st;
  return (delay > 0.0 ? set_new_event(evnt) : eventm_dispatch(evnt));
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
