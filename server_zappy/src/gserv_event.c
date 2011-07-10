/*
** gserv_event.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"tserver.h"

extern t_server	*gserv;

t_list		**singleton_event(void)
{
  static t_list *event_manager = NULL;

  return ((gserv_const(false) ? &gserv->event.dispatch : &event_manager));
}

t_list		*get_events(void)
{
  return (*(singleton_event()));
}

bool		set_new_event(t_event *event)
{
  return (put_in_list(singleton_event(), event));
}
