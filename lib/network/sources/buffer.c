/*
** buffer.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define		NETPRIVATE

#include        <unistd.h>
#include        <stdlib.h>
#include        <string.h>
#include        <stdio.h>
#include        <errno.h>

#include        "network.h"

char            *buffer_fill(char *buffer, char *s)
{
  int           i;

  if (buffer && s && ((i = strlen(buffer)) < BUFFERS))
    {
      strncpy(&buffer[i], s,  (BUFFERS - i));
      return (((BUFFERS - i) < (int)strlen(s)) ? &s[(BUFFERS - i)] : NULL);
    }
  return (s);
}

buffer          buffer_add(buffer *l, char *s)
{
  buffer                tmp;
  buffer                new;

  if ((tmp = *l))
    {
      while (tmp && tmp->next)
        tmp = tmp->next;
      if (tmp && !(s = buffer_fill(tmp->buf, s)))
        return (tmp);
    }
  if ((new = calloc(1, sizeof(*new))))
    {
      new->update = 1;
      if ((*l))
        {
          if (tmp)
            tmp->next = new;
          new->prev = tmp;
        }
      else
        *l = new;
      if ((s = buffer_fill(new->buf, s)))
        return (buffer_add(l, s));
    }
  return (new);
}

int             buffer_size(buffer b)
{
  int           i;

  i = 0;
  while (b)
    {
      if (b->next || !(strlen(b->buf) < BUFFERS - 1))
        i++;
      b = b->next;
    }
  return (i);
}

buffer          buffer_remove(buffer e)
{
  buffer                prev;
  buffer                next;

  if ((e != NULL))
    {
      if ((prev = e->prev))
        prev->next = e->next;
      if ((next = e->next))
        next->prev = e->prev;
      if (e->plus)
        free(e->plus);
      free(e);
      return ((prev ? prev : next));
    }
  return (NULL);
}

int             buffer_move(buffer l, int i)
{
  if (l && (i <= BUFFERS) && (strlen(&l->buf[i]) > 0))
    {
      strncpy(l->buf, &l->buf[i], strlen(&l->buf[i]) + 1);
      return (0);
    }
  else if (l && i <= BUFFERS && strlen(&l->buf[i]) == 0)
    return (-1);
  return (1);
}
