/*
** util_string.c for Zappy in ./common/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<strings.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<ctype.h>
#include	<errno.h>

char		*lowercase(char *s)
{
  size_t	i;
  char		*p;

  i = 0;
  p = NULL;
  if ((p = strdup(s)))
    while (p && p[i])
      {
	p[i] = tolower(p[i]);
	i += 1;
      }
  return (p);
}

