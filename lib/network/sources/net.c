/*
** network.c for  in /home/di-mar_j//svn/ftp/trunk/server
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Thu Mar 31 17:17:22 2011 julien di-marco
** Last update Thu Mar 31 17:17:22 2011 julien di-marco
*/

#include        <strings.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        <string.h>
#include        <stdio.h>

#include        <sys/types.h>
#include        <sys/socket.h>
#include        <sys/time.h>
#include        <sys/resource.h>

#include        <ifaddrs.h>
#include        <arpa/inet.h>
#include	<netdb.h>

#include        "network.h"

#define h_addr h_addr_list[0]

/*
** ssocket - Server Socket
**
*/

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

int             solimit(fds fd)
{
  struct rlimit rl;
  int           i;
  int           r;

  i = 0;
  r = 0;
  while (fd)
    {
      if (fd->fd != -1)
        i++;
      fd = fd->next;
    }
  if ((r = getrlimit(RLIMIT_NOFILE, &rl)) != -1 && (i < (int)rl.rlim_cur))
    return (0);
#if defined(ERRORMSG)
  else if (r == -1)
    fprintf(stderr, "Pool: getrlimit: %s\n", strerror(errno));
  else
    fprintf(stderr, "Pool: filedescriptor limit exceed\n");
#endif
  return (-1);
}
