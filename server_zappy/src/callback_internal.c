/*
** callback_internal.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Fri Jul  1 16:27:51 2011 Julien Di Marco
** Last update Fri Jul  1 16:27:51 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"callback.h"
#include	"client.h"
#include	"net.h"

bool		callback_(fds c, char *cmd, double _)
{
  t_client	*info;
  t_callback	*callback;

  (void)_;
  if (!c || !(info = c->trick) || !cmd)
    return (false);
  callback = &info->callback;
  return ((callback->_call ? true : false));
}

bool		callback_handler(fds c, char *s)
{
  t_client	*info;
  t_callback	*callback;
  bool		o;

  o = false;
  if (!c || !(info = c->trick))
    return (o);
  callback = &info->callback;
  if (!callback->_call)
    return (o);
  if ((o = callback->_call(c, s, callback->data)))
    memset(callback, 0, sizeof(*callback));
  flood_read(c);
  return (o);
}
