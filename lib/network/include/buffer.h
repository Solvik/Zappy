/*
** buffer.h for Zappy in ./lib/network/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef         BUFFER_H_
# define        BUFFER_H_

#define BUFFERS 4096

#define DELIM   '\n'
#define CRLF    "\r\n"

#if	defined(NETPRIVATE)
typedef struct          _buffer
{
  char                  buf[BUFFERS + 1];
  char                  *plus;

  size_t                read;
  size_t                write;
  char                  update  : 1;
  char                  circle  : 1;

  struct _buffer        *prev;
  struct _buffer        *next;
}                       _buffer;
#endif

typedef struct _buffer	*buffer;

char            *buffer_fill(char *buffer, char *s);
buffer		buffer_add(buffer *l, char *s);
int		buffer_size(buffer b);
buffer		buffer_remove(buffer e);
int		buffer_move(buffer l, int i);
void            *buffer_destroy(buffer *l);
buffer          buffer_char(buffer *l, char c);

#endif          /* !BUFFER_H_ */
