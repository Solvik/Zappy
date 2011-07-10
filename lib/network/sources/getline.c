/*
** getline.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define		NETPRIVATE

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
	  buffer_remove(f);
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
      new->update = 1;
      buffer_fill(new->buf, s);
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

static char	*check_end(fds f, buffer node, char *d)
{
  char		*r;
  int		i;

  i = -1;
  r = NULL;
  while (node->buf[++i])
    if ((((d && d[0]) && strncmp(&node->buf[i], d, strlen(d)) == 0) ||
	 ((!d || (d && !d[0])) && node->buf[i] == DELIM)) ||
	(!node->next && !node->buf[i + 1] &&
	 ((buffer_size(f->read) == READM) || !fds_alive(f))))
      {
	i += (get_size(node) - strlen(node->buf));
	if ((r = pop(&node)))
	  {
	    i = (r[i - 1] == '\r' ? i - 1 : i);
	    strncpy(d, &r[i], ((d && d[0] &&
				strlen(d) < DELIMS) ? strlen(d) :
			       (r[i] == '\r' ? 2 : 1)));
	    f->read = (r[i + 1] == '\0') ? NULL :
	      push(&node, r + i + strlen(d));
	    r[i] = '\0';
	  }
	return (r);
      }
  return (r);
}

char		*getcmd(fds filed)
{
  buffer	tmp;
  char		*r;

  if (filed && (tmp = filed->read) && filed->read->update)
    while (tmp)
      {
	if ((r = check_end(filed, tmp, filed->delim)))
	  {
	    if (filed && filed->read)
	      filed->read->update = 1;
	    return (r);
	  }
	tmp = tmp->next;
      }
  if (filed && filed->read)
    filed->read->update = 0;
  return (NULL);
}

