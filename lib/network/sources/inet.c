/*
** inet.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include        <unistd.h>
#include        <stdlib.h>
#include        <string.h>
#include        <stdio.h>

#include        <sys/types.h>
#include        <sys/socket.h>

#include        <ifaddrs.h>
#include        <arpa/inet.h>

#include        "network.h"

/*
** hostipv4
**	localhostname
*/

static int      ifaddrsize(ifaddrs *list)
{
  int           i;

  i = 0;
  while (list)
    {
      if (list->ifa_addr && (list->ifa_addr->sa_family == AF_INET))
        i += 1;
      list = list->ifa_next;
    }
  return (i);
}

static int	hostipv4(ifaddrs *addr, ipv4 **ips, int i)
{
  if (addr && ips)
    {
      if (addr->ifa_addr && (addr->ifa_addr->sa_family == AF_INET) &&
	  (strcmp(LO, addr->ifa_name) != 0) &&
	  (ips[++i] = calloc(1, sizeof(*ips[i]))))
	{
	  inet_ntop(AF_INET, &((struct sockaddr_in*)addr->ifa_addr)->sin_addr,
		    ips[i]->ip, IPV4);
	  ips[i]->split = NULL;
	}
    }
  return (i);
}

ipv4            **gethostipv4(void)
{
  ifaddrs       *addr;
  ifaddrs	*tmp;
  ipv4          **ips;
  int           i;

  i = -1;
  ips = NULL;
  addr = NULL;
  if (getifaddrs(&addr) != -1 && \
      (ips = calloc((ifaddrsize(addr) + 2), sizeof(*ips))))
    {
      tmp = addr;
      while (addr)
        {
	  i = hostipv4(addr, ips, i);
          addr = addr->ifa_next;
        }
      freeifaddrs(tmp);
    }
  return (ips);
}

/*
**
**
*/

void            *freeipv4(ipv4 **local)
{
  int           i;

  i = -1;
  if (local)
    {
      while (local && local[++i])
        free(local[i]);
      free(local);
    }
  return (NULL);
}
