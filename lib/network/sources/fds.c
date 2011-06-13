/*
** fds.c for  in /home/di-mar_j//svn/irc/branches/network
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Apr 19 17:12:10 2011 julien di-marco
** Last update Tue Apr 19 17:12:10 2011 julien di-marco
*/

#define NETPRIVATE

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>
#include	<time.h>

#include	"network.h"

fds		add_fd(fds *l, int fd, int type)
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

void		*remove_fds(fds *l, fds e)
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
      free_buffer(&e->read);
      free_buffer(&e->write);
      free_socket(e->s);
      e->fd = -1;
      free(e);
    }
  return (NULL);
}

void		*free_fds(fds *l)
{
  if ((*l))
    {
      free_fds(&((*l)->next));
      free_data((*l)->data);
      free_buffer(&(*l)->read);
      free_buffer(&(*l)->write);
      free_socket((*l)->s);
      (*l)->fd = -1;
       free((*l));
      *l = NULL;
    }
  return (NULL);
}

void            *free_buffer(buffer *l)
{
  if ((*l))
    {
      free_buffer(&((*l)->next));
      if ((*l)->plus)
        free((*l)->plus);
      free((*l));
      *l = NULL;
    }
  return (NULL);
}

void		*free_socket(sock *ket)
{
  if (ket)
    {
      if (ket->socket != -1)
	close(ket->socket);
      ket->socket = -1;
      free(ket);
    }
  return ((ket = NULL));
}
