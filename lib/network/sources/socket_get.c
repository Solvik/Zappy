/*
** socket_get.c for  in /Users/Lifely/Developer/project/Zappy/lib/network/sources
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sun Jul  3 16:02:35 2011 Julien Di Marco
** Last update Sun Jul  3 16:02:35 2011 Julien Di Marco
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
