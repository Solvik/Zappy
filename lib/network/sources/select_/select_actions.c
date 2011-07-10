/*
** select_actions.c for Zappy in ./lib/network/sources/select_
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#if		defined(SELECT_)
#define		NETPRIVATE
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>

#include	"network.h"
#include	"select_.h"

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
  if (socket && fds_alive(socket) && socket->type == SERV &&
      list && !solimit(*list) && (s = calloc(1, sizeof(*s))))
    {
      if ((s->socket = accept(socket->fd, \
			      (struct sockaddr*)&s->bind, &len)) != -1)
	{
	  if ((new = fds_add(list, s->socket, RDWR)))
	    {
	      new->s = s;
	      new->port = (socket->s ? socket->s->port : -1);
	      if (new->s)
		new->s->port = new->port;
	    }
	  else
	    socket_destroy(s);
	}
      else
	error("Accept: %s", strerror(errno));
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
  if (socket && fds_alive(socket) && (buffer_size(socket->read) < READM))
    {
      if ((i = read(socket->fd, tmp, READB)) > 0)
	{
	  buffer_add(&socket->read, tmp);
	  if (socket && socket->read)
	    socket->read->update = 1;
	}
      else
	{
	  if (i == -1)
	    error("Read Handle: %s", strerror(errno));
	  socket_close(socket->s);
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
  int		a;

  if (socket && fds_alive(socket) && socket->write)
    {
      if ((i = write(socket->fd, socket->write->buf,
		     (a = strlen(socket->write->buf)) > WRITEB ?
		     WRITEB : a)) > 0)
	{
	  if (buffer_move(socket->write, i) == -1)
	    socket->write = buffer_remove(socket->write);
	}
      else
      	{
	  error("Write Handle: %s", strerror(errno));
	  socket_close(socket->s);
      	  return (-1);
      	}
    }
  return (0);
}

#endif		/* !SELECT_ */
