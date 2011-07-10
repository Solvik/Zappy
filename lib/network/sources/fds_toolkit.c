/*
** fds_toolkit.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define		NETPRIVATE
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"buffer.h"
#include	"network.h"

int		fds_alive(fds c)
{
  if (!c)
    return (0);
  return ((socket_fd(c->s) == -1 ? 0 : 1));
}

void		fds_close(fds c)
{
  if (!c)
    return ;
  socket_close(c->s);
  buffer_destroy(&c->write);
}
