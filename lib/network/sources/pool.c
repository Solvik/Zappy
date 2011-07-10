/*
** pool.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<sys/select.h>
#include	<sys/types.h>
#include	<sys/time.h>
#include	<time.h>

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"network.h"

static struct timeval	*timeval_(struct timeval *t, double time)
{
  static struct timeval	tv;

  if ((time < 0))
    return (t);
  if (!t)
    {
      tv.tv_sec = time / 1;
      tv.tv_usec = (time - tv.tv_sec) * 1000000.0;
    }
  return ((t ? t : &tv));
}

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
  int		t;

  if ((*l) && ((t = pool_fill((*l), &p)) != -1))
    {
      tv = ((t == 1) ? timeval_(tv, 0.05) : tv);
      if ((pool_exec(&p, tv) != -1))
	pool_handle(l, &p);
    }
  return ((*l));
}
