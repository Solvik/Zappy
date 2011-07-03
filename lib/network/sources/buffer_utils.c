/*
** buffer_utils.c for  in /Users/Lifely/Developer/project/Zappy/lib/network/sources
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sun Jul  3 15:07:11 2011 Julien Di Marco
** Last update Sun Jul  3 15:07:11 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#define		NETPRIVATE
#include	"buffer.h"
#include	"network.h"

/*
** Function: buffer_lastone - BufferToolkit
**
** This function return the last chunk in a bufferStack.
**
** Return the last chunk of a given bufferStack.
*/

static buffer	buffer_lastone(buffer e)
{
  while (e && e->next)
    e = e->next;
  return (e);
}

/*
** Function: buffer_char - BufferToolkit
**
** This function add only one charactere to a buffer stack.
** it can modify the buffer stack head.
**
** Return the chunk were the charactere have been added.
*/

buffer          buffer_char(buffer *l, char c)
{
  buffer                tmp;
  buffer                new;
  char			s[BUFFERS + 1];
  char			*cheat;

  memset(s, 0, BUFFERS + 1);
  s[0] = c;
  cheat = NULL;
  new = NULL;
  if ((tmp = buffer_lastone(*l)) && !(cheat = buffer_fill(tmp->buf, s)))
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
      if ((cheat = buffer_fill(new->buf, cheat)))
        return (buffer_add(l, cheat));
    }
  return (new);
}
