/*
** writeline.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define		_GNU_SOURCE
#define		NETPRIVATE

#include	<stdbool.h>
#include	<unistd.h>
#include	<stdarg.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"network.h"

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
  if (filed && fds_alive(filed))
    {
      filed->anounce = s ? 1 : filed->anounce;
      if (s)
	buffer_add(&filed->write, s);
      if (s && end)
	buffer_add(&filed->write, filed->delim[0] ? filed->delim : "\n");
    }
}

int		sendf(fds c, char const *format, ...)
{
  char		*string;
  va_list	arguments;

  if (!c || !fds_alive(c))
    return (false);
  string = NULL;
  va_start(arguments, format);
  if (vasprintf(&string, format, arguments) == -1)
    return (false);
  va_end(arguments);
  if (string)
    {
      buffer_add(&c->write, string);
      buffer_add(&c->write, c->delim[0] ? c->delim : "\n");
      free(string);
    }
  return (true);
}

int		sendf_(fds c, int s, char const *format, ...)
{
  char		*string;
  va_list	arguments;

  if (!c || !fds_alive(c))
    return (false);
  string = NULL;
  va_start(arguments, format);
  if (vasprintf(&string, format, arguments) == -1)
    return (false);
  va_end(arguments);
  if (string)
    {
      buffer_add(&c->write, string);
      if (s)
	buffer_add(&c->write, c->delim[0] ? c->delim : "\n");
      free(string);
    }
  return (true);
}

