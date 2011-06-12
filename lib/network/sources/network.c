/*
** network.c for  in /home/di-mar_j//svn/irc/branches/network
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Apr 19 22:15:47 2011 julien di-marco
** Last update Tue Apr 19 22:15:47 2011 julien di-marco
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

#define ERRORMSG

int		handle_serv(fds *list, fds socket)
{
  fds		new;
  sock		*s;
  socklen_t	len;

  len = sizeof(saddri);
  if (socket && socket->fd != -1 && socket->type == SERV && \
      list && !solimit(*list) && (s = calloc(1, sizeof(*s))))
    {
      if ((s->socket = accept(socket->fd, \
			      (struct sockaddr*)&s->bind, &len)) != -1)
	{
	  if ((new = add_fd(list, s->socket, RDWR)))
	    new->s = s;
	  else
	    free_socket(s);
	}
#if defined(ERRORMSG)
      else
	fprintf(stderr, "Pool: Accept: %s\n", strerror(errno));
#endif
    }
  return (0);
}

int		handle_read(fds socket)
{
  char		tmp[READB + 1];
  int		i;

  i = 0;
  memset(tmp, 0, (READB + 1));
  if (socket && (socket->fd != -1) && (size_buffer(socket->read) < READM))
    {
      if ((i = read(socket->fd, tmp, READB)) > 0)
	add_buffer(&socket->read, tmp);
      else
	{
#if defined(ERRORMSG)
	  if (i == -1)
	    fprintf(stderr, "Pool: Read Handle: %s\n", strerror(errno));
#endif
	  close(socket->fd);
	  socket->fd = -1;
	  return (-1);
	}
    }
  return (0);
}

int		handle_write(fds socket)
{
  int		i;

  if (socket && (socket->fd != -1) && socket->write)
    {
      if ((i = write(socket->fd, socket->write->buf, \
		     (((i = strlen(socket->write->buf)) > WRITEB) \
		      ? i : WRITEB))) > 0)
	{
	  if (move_buffer(socket->write, i) == -1)
	    socket->write = remove_buffer(socket->write);
	}
      else
      	{
#if defined(ERRORMSG)
      	  fprintf(stderr, "Pool: Write Handle: %s\n", strerror(errno));
#endif
	  close(socket->fd);
      	  socket->fd = -1;
      	  return (-1);
      	}
    }
  return (0);
}

int		add_socket(fds *pool, int p, int q)
{
  sock		*s;
  fds		fd;

  fd = NULL;
  if (pool && (s = ssocket(p, q)))
    {
      if ((fd = add_fd(pool, s->socket, SERV)))
	{
	  fd->s = s;
	  return (0);
	}
      free_socket(s);
      return (1);
    }
  return (-1);
}

int		add_co(fds *pool, char *hostname, int p)
{
  sock		*s;
  fds		fd;

  fd = NULL;
  if (pool && (s = csocket(hostname, p)))
    {
      if ((fd = add_fd(pool, s->socket, RDWR)))
	{
	  fd->s = s;
	  return (0);
	}
      free_socket(s);
      return (1);
    }
  return (-1);
}
