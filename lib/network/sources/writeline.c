/*
** writeline.c for  in /home/di-mar_j//svn/irc/trunk/server
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Fri Apr 22 17:34:29 2011 julien di-marco
** Last update Fri Apr 22 17:34:29 2011 julien di-marco
*/

#define NETPRIVATE

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"network.h"

/*
** Function: lastone - BufferToolkit
**
** This function return the last chunk in a bufferStack.
**
** Return the last chunk of a given bufferStack.
*/

static buffer	lastone(buffer e)
{
  while (e && e->next)
    e = e->next;
  return (e);
}

/*
** Function: add_char - BufferToolkit
**
** This function add only one charactere to a buffer stack.
**
** it can modify the buffer stack head.
**
** Return the chunk were the charactere have been added.
*/

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

/*
** Function: writes - Public
**
** This function is user triggered to send something
** to sa specific fds.
** The buffer are correctly ajusted and the client 'll receive the
** content as soon as possible.
**
*/

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
