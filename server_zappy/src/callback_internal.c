/*
** callback_internal.c for Zappy in ./server_zappy/src
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
