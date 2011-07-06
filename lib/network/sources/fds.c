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

void		*fds_remove(fds *l, fds e)
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
      free_data(e->data);
      buffer_destroy(&e->read);
      buffer_destroy(&e->write);
      socket_destroy(e->s);
      e->fd = -1;
      free(e);
    }
  return (NULL);
}

void		*fds_destroy(fds *l)
{
  if ((*l))
    {
      fds_destroy(&((*l)->next));
      free_data((*l)->data);
      buffer_destroy(&(*l)->read);
      buffer_destroy(&(*l)->write);
      socket_destroy((*l)->s);
      (*l)->fd = -1;
       free((*l));
      *l = NULL;
    }
  return (NULL);
}
