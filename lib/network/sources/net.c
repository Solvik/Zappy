/*
** net.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define		NETPRIVATE

#include        <strings.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        <string.h>
#include        <stdio.h>
#include	<errno.h>

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

int             solimit(fds fd)
{
  struct rlimit rl;
  int           i;
  int           r;

  i = 0;
  r = 0;
  while (fd)
    {
      i += (fds_alive(fd) ? 1 : 0);
      fd = fd->next;
    }
  if ((r = getrlimit(RLIMIT_NOFILE, &rl)) != -1 && (i < (int)rl.rlim_cur))
    return (0);
  error((r == 1) ? "getrlimit: %s" : "filedescriptor limit exceed",
	strerror(errno));
  return (-1);
}
