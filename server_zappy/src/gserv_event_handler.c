/*
** gserv_event_handler.c for Zappy in ./server_zappy/src
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

#include	"tserver.h"

extern t_server	*gserv;

t_list		**singleton_event_handler(void)
{
  static t_list	*event_handler = NULL;

  return ((gserv_const(false) ? &gserv->event.catch : &event_handler));
}

t_list		*get_catchers(void)
{
  return (*(singleton_event_handler()));
}

static bool	match_catcher(void *elem, void *arg)
{
  t_catch	*e;
  t_catch	*a;

  if (!(e = elem) || !(a = arg) ||
      !e->name || !a->name)
    return (false);
  if ((strcasecmp(e->name, a->name) == 0))
    return (true);
  return (false);
}

bool		set_new_catcher(t_catch *catcher)
{
  t_catch	*brother;
  if (!catcher || !catcher->name)
    return (false);
  if ((brother = get_data_as_arg(get_catchers(), match_catcher, catcher)))
    return (put_in_list(&brother->catch, catcher));
  return (put_in_list(singleton_event_handler(), catcher));
}
