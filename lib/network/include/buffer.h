/*
** buffer.h for  in /home/di-mar_j//git/Zappy/lib/network
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Mon Jun 13 12:48:08 2011 julien di-marco
** Last update Mon Jun 13 12:48:08 2011 julien di-marco
*/

#ifndef         BUFFER_H_
# define        BUFFER_H_

#define BUFFERS 4096

#define DELIM   '\n'
#define CRLF    "\r\n"

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

#endif          /* !BUFFER_H_ */
