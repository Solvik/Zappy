/*
** pool.c for  in /home/di-mar_j//svn/irc/branches/network
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Fri Apr 22 12:38:07 2011 julien di-marco
** Last update Sat Apr 23 15:41:42 2011 dimitri jorge
*/

#include	<sys/select.h>
#include	<sys/types.h>
#include	<sys/time.h>

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"network.h"

void		*(*free_data)(void *data) = NULL;

static int	fdfull(fds l, fd_set *read, fd_set *write, fd_set *error)
{
  int		i;

  i = -1;
  FD_ZERO(read);
  FD_ZERO(write);
  FD_ZERO(error);
  while (l && read && write && error)
    {
      if (l && l->fd != -1)
	{
	  FD_SET(l->fd, error);
	  if (((l->type == READ || l->type == RDWR) && \
	       (size_buffer(l->read) < READM)) || l->type == SERV)
	    FD_SET(l->fd, read);
	  if ((l->type == WRITE || l->type == RDWR) && l->write)
	    FD_SET(l->fd, write);
	  i = (l->fd > i ? l->fd : i);
	}
      l = l->next;
    }
  return (i);
}

static int	select_handle(fds *l, fd_set *read, fd_set *write, fd_set *error)
{
  fds		tmp;

  tmp = (*l);
  while (tmp && read && write && error)
    {
      if ((tmp->fd != -1) && tmp->type == SERV && FD_ISSET(tmp->fd, read))
	handle_serv(l, tmp);
      if ((tmp->fd != -1) && (tmp->type == READ || tmp->type == RDWR) && \
	  FD_ISSET(tmp->fd, read))
	handle_read(tmp);
      if ((tmp->fd != -1) && (tmp->type == WRITE || tmp->type == RDWR) && \
	  FD_ISSET(tmp->fd, write))
	handle_write(tmp);
      tmp = tmp->next;
    }
  return (0);
}

fds		pool(fds *l)
{
  struct timeval tv;
  fd_set	read;
  fd_set	write;
  fd_set	error;
  int		max;

  tv.tv_sec = 0;
  tv.tv_usec = 500;
  if ((*l) && (max = fdfull((*l), &read, &write, &error)) != -1)
    {
      if (select((max + 1), &read, &write, &error, &tv) != -1)
	  select_handle(l, &read, &write, &error);
    }
  return ((*l));
}
