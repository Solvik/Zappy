/*
** getline.c for  in /home/di-mar_j//svn/irc/branches/network
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Apr 21 23:16:56 2011 julien di-marco
** Last update Thu Apr 21 23:16:56 2011 julien di-marco
*/

#define NETPRIVATE

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"network.h"

static int	get_size(buffer b)
{
  int		s;

  s = 0;
  while (b)
    {
      s += strlen(b->buf);
      b = b->prev;
    }
  return (s);
}

static char	*pop(buffer *b)
{
  buffer	t;
  buffer	f;
  char		*r;

  r = NULL;
  if (b && (t = *b) && (r = calloc(get_size(*b) + 2, sizeof(*r))))
    {
      *b = (*b)->next;
      while (t)
	{
	  strncpy(r + (get_size(t) - strlen(t->buf)), t->buf, strlen(t->buf));
	  f = t;
	  t = t->prev;
	  remove_buffer(f);
	}
    }
  return (r);
}

static buffer	push(buffer *bf, char *s)
{
  buffer		tmp;
  buffer		new;

  if ((new = calloc(1, sizeof(*new))))
    {
      fill_buffer(new->buf, s);
      if ((tmp = *bf))
	{
	  if (tmp)
	    tmp->prev = new;
	  new->next = tmp;
	}
      else
	*bf = new;
    }
  return (new);
}

char		*getcmd(fds filed)
{
  buffer	tmp;
  char		*r;
  int		i;

  if (filed && (tmp = filed->read))
    {
      while (tmp)
	{
	  i = -1;
	  while (tmp->buf[++i])
	    if (tmp->buf[i] == DELIM || (!tmp->next && !tmp->buf[i + 1] && \
					 ((size_buffer(filed->read) == READM) || \
					  filed->fd == -1)))
	      {
		i += (get_size(tmp) - strlen(tmp->buf));
		if ((r = pop(&tmp)))
		    filed->read = (r[i + 1] == '\0') ? NULL : push(&tmp, r + i + 1);
		if (r)
		  r[(r[i - 1] == '\r' ? i - 1 : i)] = '\0';
		return (r);
	      }
	  tmp = tmp->next;
	}
    }
  return (NULL);
}

