/*
** fds.c for  in /home/di-mar_j//svn/irc/branches/network
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Apr 19 17:12:10 2011 julien di-marco
** Last update Tue Apr 19 17:12:10 2011 julien di-marco
*/

#define		NETPRIVATE

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>
#include	<time.h>

#include	"network.h"

fds		fds_add(fds *l, int fd, int type)
{
  fds		tmp;
  fds		new;

  new = NULL;
  if (!solimit(*l) && (new = calloc(1, sizeof(*new))))
    {
      new->fd = fd;
      time(&new->time);
      new->type = type;
      if ((tmp = *l))
	{
	  while (tmp && tmp->next)
	    tmp = tmp->next;
	  if (tmp)
	    tmp->next = new;
	  new->prev = tmp;
	}
      else
	*l = new;
    }
  return (new);
}

void		*fds_remove(fds *l, fds e, void *(*free_data)(void *))
{
  fds		prev;
  fds		next;

  if ((e != NULL))
    {
      if ((prev = e->prev))
	prev->next = e->next;
      if ((next = e->next))
	next->prev = e->prev;
      if ((*l) == e)
	(*l) = e->next;
      fds_free(e, free_data);
    }
  return (NULL);
}

void		*fds_free(fds c, void *(*free_data)(void *))
{
  if (c)
    {
      if (free_data)
	c->data = free_data(c->data);
      buffer_destroy(&c->read);
      buffer_destroy(&c->write);
      socket_destroy(c->s);
      c->fd = -1;
      free(c);
    }
  return ((c = NULL));
}

void		*fds_destroy(fds *l, void *(*free_data)(void*))
{
  if ((*l))
    {
      fds_destroy(&((*l)->next), free_data);
      *l = fds_free(*l, free_data);
    }
  return (NULL);
}
