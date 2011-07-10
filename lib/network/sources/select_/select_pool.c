/*
** select_pool.c for Zappy in ./lib/network/sources/select_
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#if		defined(SELECT_)
#define		NETPRIVATE
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"network.h"
#include	"select_.h"

/*
** Function: fdfull - private
** Called by pool
**
** This function handle the different fd_set (read, write, error)
** and fill each set according to each specific fds.
*/

/*
** pool_fill is call by pool to set all the fd that need to be set.
**
** Return is important as:
** -1 means no pool_exec is needed
** 0  means pool_exec should exec normaly
** 1  there is already something on, at least one, a read buffer
*/

int		pool_fill(fds l, t_select *p)
{
  int		r;

  if (!l || !p || ((r = 0) != 0))
    return (-1);
  p->max = -1;
  FD_ZERO(&p->read);
  FD_ZERO(&p->write);
  FD_ZERO(&p->error);
  while (l && p)
    {
      if (l && fds_alive(l))
	{
	  FD_SET(l->fd, &p->error);
	  if (((l->type == READ || l->type == RDWR) && \
	       (buffer_size(l->read) < READM)) || l->type == SERV)
	    FD_SET(l->fd, &p->read);
	  if ((l->type == WRITE || l->type == RDWR) && l->write)
	    FD_SET(l->fd, &p->write);
	  p->max = (l->fd > p->max ? l->fd : p->max);
	}
      r = (l && l->read && l->read->update) ? 1 : r;
      l = l->next;
    }
  return ((p->max == -1 ? -1 : (r ? 1 : 0)));
}

/*
** Function: select_handle - Private
** Called by pool
**
** This function pass on each fds to check if something happend.
*/

int		pool_handle(fds *l, t_select *p)
{
  fds		tmp;
  int		i;

  tmp = (*l);
  i = 0;
  while (p && (i < p->isset) && tmp)
    {
      if (fds_alive(tmp) && tmp->type == SERV &&
	  FD_ISSET(tmp->fd, &p->read) && ++i)
	handle_serv(l, tmp);
      if (fds_alive(tmp) && (tmp->type == READ || tmp->type == RDWR) && \
	  FD_ISSET(tmp->fd, &p->read) && ++i)
	handle_read(tmp);
      if (fds_alive(tmp) && (tmp->type == WRITE || tmp->type == RDWR) && \
	  FD_ISSET(tmp->fd, &p->write) && ++i)
	handle_write(tmp);
      tmp = tmp->next;
    }
  return (0);
}

int		pool_exec(t_select *p, struct timeval *t)
{
  if (!p)
    return (-1);
  return ((p->isset = select(p->max + 1, &p->read, &p->write, &p->error, t)));
}

#endif		/* !SELECT_ */
