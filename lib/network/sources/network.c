/*
** network.c for  in /home/di-mar_j//svn/irc/branches/network
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Apr 19 22:15:47 2011 julien di-marco
** Last update Tue Apr 19 22:15:47 2011 julien di-marco
*/

#define NETPRIVATE

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

/*
** Function: handle_serv - private
**
** Handle the action the lib have to make when a file descriptor
** is able to accepte new connection.
** Generaly the type of this fds is [SERV].
**
** Return not use for now.
*/

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
	  if ((new = fds_add(list, s->socket, RDWR)))
	    {
	      new->s = s;
	      new->port = (socket->s ? socket->s->port : -1);
	    }
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

/*
** Function: handle_read - private
**
** Handle the action the lib have to make when a file descriptor
** is readable without blocking, assuming the buffer are okay
** The type of the fds is [READ | RDWR].
**
** Return -1 on error.
*/

int		handle_read(fds socket)
{
  char		tmp[READB + 1];
  int		i;

  i = 0;
  memset(tmp, 0, (READB + 1));
  if (socket && (socket->fd != -1) && (buffer_size(socket->read) < READM))
    {
      if ((i = read(socket->fd, tmp, READB)) > 0)
	buffer_add(&socket->read, tmp);
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

/*
** Function: handle_write - private
**
** Handle the action the lib have to make when a file descriptor
** is writable and fetch the buffer to write on it.
** Generaly the type of this fds is [WRITE | RDWR].
**
** Note: this function is only trigger when there is a least one
** charactere in the write buffer.
**
** Return -1 on failure.
*/

int		handle_write(fds socket)
{
  int		i;

  if (socket && (socket->fd != -1) && socket->write)
    {
      if ((i = write(socket->fd, socket->write->buf, \
		     (((i = strlen(socket->write->buf)) > WRITEB) \
		      ? i : WRITEB))) > 0)
	{
	  if (buffer_move(socket->write, i) == -1)
	    socket->write = buffer_remove(socket->write);
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

/*
** Function: add_socket - public - user triggered
**
** This function is triggered by the user to add listen
** on a specific port on the machine and wait for client.
**
** Return -1 on failure.
*/

int		add_socket(fds *pool, int p, int q)
{
  sock		*s;
  fds		fd;

  fd = NULL;
  if (pool && (s = ssocket(p, q)))
    {
      if ((fd = fds_add(pool, s->socket, SERV)))
	{
	  fd->s = s;
	  return (0);
	}
      free_socket(s);
      return (1);
    }
  return (-1);
}

/*
** Function: add_co - public - user triggered
**
** This function is trigger by the user when he want to connect
** on a specific hostname [hostname] and on a specific port
** [p].
**
** Return -1 on failure.
*/

int		add_co(fds *pool, char *hostname, int p)
{
  sock		*s;
  fds		fd;

  fd = NULL;
  if (pool && (s = csocket(hostname, p)))
    {
      if ((fd = fds_add(pool, s->socket, RDWR)))
	{
	  fd->s = s;
	  return (0);
	}
      free_socket(s);
      return (1);
    }
  return (-1);
}
