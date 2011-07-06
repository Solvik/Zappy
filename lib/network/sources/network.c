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
      socket_destroy(s);
      return (1);
    }
  return (-1);
}

/*
** Function: add_co - public - user triggered
**
** This function is trigger by the user when he want to connect
** on a specific hostname [hostname] and on a specific port [p].
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
      socket_destroy(s);
      return (1);
    }
  return (-1);
}
