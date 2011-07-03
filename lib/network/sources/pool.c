/*
** pool.c for  in /home/di-mar_j/git/Zappy/server_zappy/src
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 22 17:43:40 2011 julien di-marco
** Last update Wed Jun 22 17:43:40 2011 julien di-marco
*/

#include	<sys/select.h>
#include	<sys/types.h>
#include	<sys/time.h>

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"network.h"

void		*(*free_data)(void *data) = NULL;

/*
** Function: pool - public
**
** This function have to be call periodicly.
** The fdsList contain all fds to manage in read - write and other.
**
** Return the fdsList.
*/

fds		pool(fds *l, struct timeval *tv)
{
  static t_pool	p;

  if ((*l) && (p.max = pool_fill((*l), &p)) != -1)
    if ((pool_exec(&p, tv) != -1))
      pool_handle(l, &p);
  return ((*l));
}
