/*
** fds_toolkit.c for  in /home/di-mar_j/git/Zappy/lib/network/sources
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jul  6 03:29:17 2011 julien di-marco
** Last update Wed Jul  6 03:29:17 2011 julien di-marco
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
