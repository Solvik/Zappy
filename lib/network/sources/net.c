/*
** network.c for  in /home/di-mar_j//svn/ftp/trunk/server
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Thu Mar 31 17:17:22 2011 julien di-marco
** Last update Thu Mar 31 17:17:22 2011 julien di-marco
*/

#define NETPRIVATE

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
