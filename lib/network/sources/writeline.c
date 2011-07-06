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
	buffer_add(&filed->write, CRLF);
    }
}
