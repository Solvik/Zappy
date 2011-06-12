/*
** writeline.c for  in /home/di-mar_j//svn/irc/trunk/server
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Fri Apr 22 17:34:29 2011 julien di-marco
** Last update Fri Apr 22 17:34:29 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"network.h"

static buffer	lastone(buffer e)
{
  while (e && e->next)
    e = e->next;
  return (e);
}

buffer          add_char(buffer *l, char c)
{
  buffer                tmp;
  buffer                new;
  char			s[BUFFERS + 1];
  char			*cheat;

  memset(s, 0, BUFFERS + 1);
  s[0] = c;
  cheat = NULL;
  new = NULL;
  if ((tmp = lastone(*l)) && !(cheat = fill_buffer(tmp->buf, s)))
    return (tmp);
  if (cheat && (new = calloc(1, sizeof(*new))))
    {
      if ((*l))
        {
          if (tmp)
            tmp->next = new;
          new->prev = tmp;
        }
      else
        *l = new;
      if ((cheat = fill_buffer(new->buf, cheat)))
        return (add_buffer(l, cheat));
    }
  return (new);
}

void		writes(fds filed, char *s, int end)
{
  if (filed && filed->fd != -1)
    {
      if (s)
	add_buffer(&filed->write, s);
      if (s && end)
	add_buffer(&filed->write, CRLF);
    }
}
