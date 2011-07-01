/*
** callback_user.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 30 16:14:58 2011 julien di-marco
** Last update Thu Jun 30 16:14:58 2011 julien di-marco
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
