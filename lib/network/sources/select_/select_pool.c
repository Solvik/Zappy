/*
** select_pool.c for  in /Users/Lifely/Developer/project/Zappy/lib/network/sources
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sun Jul  3 17:12:21 2011 Julien Di Marco
** Last update Sun Jul  3 17:12:21 2011 Julien Di Marco
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
** This function handle the different fd_set (read,write,error)
** and fill each set according to each specific fds.
*/

int		pool_fill(fds l, t_select *p)
{
  if (!l || !p)
    return (-1);
  p->max = -1;
  FD_ZERO(&p->read);
  FD_ZERO(&p->write);
  FD_ZERO(&p->error);
  while (l && p)
    {
      if (l && l->fd != -1)
	{
	  FD_SET(l->fd, &p->error);
	  if (((l->type == READ || l->type == RDWR) && \
	       (buffer_size(l->read) < READM)) || l->type == SERV)
	    FD_SET(l->fd, &p->read);
	  if ((l->type == WRITE || l->type == RDWR) && l->write)
	    FD_SET(l->fd, &p->write);
	  p->max = (l->fd > p->max ? l->fd : p->max);
	}
      l = l->next;
    }
  return (p->max);
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
      if ((tmp->fd != -1) && tmp->type == SERV && FD_ISSET(tmp->fd, &p->read) && ++i)
	handle_serv(l, tmp);
      if ((tmp->fd != -1) && (tmp->type == READ || tmp->type == RDWR) && \
	  FD_ISSET(tmp->fd, &p->read) && ++i)
	handle_read(tmp);
      if ((tmp->fd != -1) && (tmp->type == WRITE || tmp->type == RDWR) && \
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
