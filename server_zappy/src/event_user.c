/*
** event_user.c for Zappy in ./server_zappy/src
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

extern t_server	*gserv;

bool		event_dispatch(char *name, void *data, double delay)
{
  t_event	*evnt;
  bool		out;

  out = false;
  if (!name || !(evnt = calloc(1, sizeof(*evnt))))
    return (false);
  evnt->name = strdup(name);
  evnt->data = data;
  evnt->delay = delay;
  evnt->st = time_();
  evnt->lt = evnt->st;
  if (delay > 0.0)
    out = set_new_event(evnt);
  else
    {
      out = eventm_dispatch(evnt);
      free(evnt);
    }
  return (out);
}

bool		event_free(char *name, void *data, double delay)
{
  t_event	*evnt;
  bool		out;

  out = false;
  if (!name || !(evnt = calloc(1, sizeof(*evnt))))
    return (false);
  evnt->name = strdup(name);
  evnt->data = data;
  evnt->delay = delay;
  evnt->free = true;
  evnt->st = time_();
  evnt->lt = evnt->st;
  if (delay > 0.0)
    out = set_new_event(evnt);
  else
    {
      out = eventm_dispatch(evnt);
      free(evnt);
    }
  return (out);
}

bool		event_relative_dispatch(char *name, void *data, double delay)
{
  t_event	*evnt;
  bool		out;

  out = false;
  if (!name || !(evnt = calloc(1, sizeof(*evnt))))
    return (false);
  evnt->name = strdup(name);
  evnt->data = data;
  evnt->delay = delay;
  evnt->relative = true;
  evnt->st = time_();
  evnt->lt = evnt->st;
  if (delay > 0.0)
    out = set_new_event(evnt);
  else
    {
      out = eventm_dispatch(evnt);
      free(evnt);
    }
  return (out);
}

bool		event_free_relative(char *name, void *data, double delay)
{
  t_event	*evnt;
  bool		out;

  out = false;
  if (!name || !(evnt = calloc(1, sizeof(*evnt))))
    return (false);
  evnt->name = strdup(name);
  evnt->data = data;
  evnt->delay = delay;
  evnt->free = true;
  evnt->relative = true;
  evnt->st = time_();
  evnt->lt = evnt->st;
  if (delay > 0.0)
    out = set_new_event(evnt);
  else
    {
      out = eventm_dispatch(evnt);
      free(evnt);
    }
  return (out);
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
