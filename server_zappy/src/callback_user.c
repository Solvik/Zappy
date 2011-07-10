/*
** callback_user.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"net.h"
#include	"client.h"
#include	"callback.h"

bool		callback_set(fds c, callback call, void *data)
{
  t_client	*info;
  t_callback	*callback;

  if (!c || !call || !(info = c->trick))
    return (false);
  callback = &info->callback;
  if (callback->_call)
    return (false);
  callback->_call = call;
  callback->data = data;
  return (true);
}

bool		callback_overide(fds c, callback call, void *data)
{
  t_client	*info;
  t_callback	*callback;

  if (!c || !call || !(info = c->trick))
    return (false);
  callback = &info->callback;
  callback->_call = call;
  callback->data = data;
  return (true);
}

bool		callback_active(fds c)
{
  t_client	*info;
  t_callback	*callback;

  if (!c || !(info = c->trick))
    return (false);
  callback = &info->callback;
  return ((callback->_call ? true : false));
}
