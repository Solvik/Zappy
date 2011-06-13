/*
** buffer.c for  in /home/di-mar_j//svn/irc/branches/network
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Tue Apr 19 17:44:38 2011 julien di-marco
** Last update Tue Apr 19 17:44:38 2011 julien di-marco
*/

#define NETPRIVATE

#include        <unistd.h>
#include        <stdlib.h>
#include        <string.h>
#include        <stdio.h>
#include        <errno.h>

#include        "network.h"

char            *fill_buffer(char *buffer, char *s)
{
  int           i;

  if (buffer && s && ((i = strlen(buffer)) < BUFFERS))
    {
      strncpy(&buffer[i], s,  (BUFFERS - i));
      return (((BUFFERS - i) < (int)strlen(s)) ? &s[(BUFFERS - i)] : NULL);
    }
  return (s);
}

buffer          add_buffer(buffer *l, char *s)
{
  buffer                tmp;
  buffer                new;

  if ((tmp = *l))
    {
      while (tmp && tmp->next)
        tmp = tmp->next;
      if (tmp && !(s = fill_buffer(tmp->buf, s)))
        return (tmp);
    }
  if ((new = calloc(1, sizeof(*new))))
    {
      if ((*l))
        {
          if (tmp)
            tmp->next = new;
          new->prev = tmp;
        }
      else
        *l = new;
      if ((s = fill_buffer(new->buf, s)))
        return (add_buffer(l, s));
    }
  return (new);
}

int             size_buffer(buffer b)
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

buffer          remove_buffer(buffer e)
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

int             move_buffer(buffer l, int i)
{
  if (l && (i <= BUFFERS) && (strlen(&l->buf[i]) > 0))
    {
      strncpy(l->buf, &l->buf[i], (BUFFERS - i));
      return (0);
    }
  else if (l && i <= BUFFERS && strlen(&l->buf[i]) == 0)
    return (-1);
  return (1);
}
