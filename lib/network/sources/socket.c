/*
** socket.c for  in /Users/Lifely/Developer/project/Zappy/lib/network/sources
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sun Jul  3 15:50:19 2011 Julien Di Marco
** Last update Sun Jul  3 15:50:19 2011 Julien Di Marco
*/

#define		NETPRIVATE
#include	<strings.h>
#include	<unistd.h>
#include	<stdlib.h>
#include        <string.h>
#include        <stdio.h>

#include	"network.h"
#include	"socket.h"

#include        <sys/types.h>
#include        <sys/socket.h>
#include        <sys/time.h>
#include        <sys/resource.h>

#include        <ifaddrs.h>
#include        <arpa/inet.h>
#include	<netdb.h>

#define h_addr h_addr_list[0]

static int      getport(sock *s)
{
  socklen_t     addrlen;

  addrlen = sizeof(saddri);
  if (s && (ntohs(s->bind.sin_port) == 0))
    {
      if (getsockname(s->socket, (struct sockaddr*)&s->bind, &addrlen) != -1)
        {
          s->port = ntohs(s->bind.sin_port);
          return (1);
        }
      return (-1);
    }
  return (0);
}

sock            *ssocket(int port, int queue)
{
  int           on;
  sock          *s;

  on = 1;
  if ((s = malloc(sizeof(*s))) && (s->pro = getprotobyname(PROTO)) &&
      ((s->socket = socket(PF_INET, SOCK_STREAM, s->pro->p_proto)) != -1))
    {
      s->port = port;
      s->queue = queue;
      setsockopt(s->socket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));
      s->bind.sin_family = AF_INET;
      s->bind.sin_port = htons(s->port);
      s->bind.sin_addr.s_addr = htons(INADDR_ANY);
      if ((bind(s->socket, (struct sockaddr *)&s->bind,
                sizeof(s->bind)) != -1) && (listen(s->socket, queue) != -1))
        if (getport(s) != -1)
          return (s);
      close(s->socket);
    }
  free(s);
  return  (NULL);
}

sock            *csocket(char *hostname, int port)
{
  struct hostent        *h;
  sock                  *s;

  h = NULL;
  printf("connecting on <%s:%d>\n", hostname, port);
  if ((s = malloc(sizeof(*s))) && (s->pro = getprotobyname(PROTO)) &&
      ((s->socket = socket(PF_INET, SOCK_STREAM, s->pro->p_proto)) != -1))
    {
      if (hostname && (h = gethostbyname(hostname)))
        {
          s->port = port;
          s->bind.sin_family = AF_INET;
          s->bind.sin_port = htons(s->port);
          bcopy(h->h_addr, &s->bind.sin_addr, sizeof(s->bind.sin_addr));
          if ((connect(s->socket, (struct sockaddr *)&s->bind,
                       sizeof(s->bind)) != -1))
            if (getport(s) != -1)
              return (s);
        }
      close(s->socket);
    }
  free(s);
  return  (NULL);
}

void		*socket_destroy(sock *ket)
{
  if (ket)
    {
      if (ket->socket != -1)
	close(ket->socket);
      ket->socket = -1;
      free(ket);
    }
  return ((ket = NULL));
}
