/*
** socket_get.c for Zappy in ./lib/network/sources
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

#include	"socket.h"

int		socket_fd(sock *et)
{
  if (!et)
    return (-1);
  return (et->socket);
}

int		socket_port(sock *et)
{
  if (!et)
    return (-1);
  return (et->port);
}

char*		socket_addr(sock *et)
{
  char		*net;

  net = NULL;
  if (!et)
    return (NULL);
  if (!(net = calloc(IPV6, sizeof(*net))) ||
      !(inet_ntop(AF_INET, &(et->bind.sin_addr), net, IPV6)))
    {
      free(net);
      net = NULL;
    }
  return (net);
}

void		socket_close(sock *et)
{
  if (!et || (et && et->socket == -1))
    return ;
  close(et->socket);
  et->socket = -1;
}
