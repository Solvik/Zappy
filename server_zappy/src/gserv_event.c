/*
** gserv_event.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Mon Jul  4 18:52:55 2011 Julien Di Marco
** Last update Mon Jul  4 18:52:55 2011 Julien Di Marco
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
