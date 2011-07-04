/*
** gserv_event_handler.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Mon Jul  4 18:56:12 2011 Julien Di Marco
** Last update Mon Jul  4 18:56:12 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<stdlib.h>

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

bool		set_new_catcher(t_catch *catcher)
{
  return (put_in_list(singleton_event_handler(), catcher));
}
