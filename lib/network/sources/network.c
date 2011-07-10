/*
** network.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define		NETPRIVATE

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
