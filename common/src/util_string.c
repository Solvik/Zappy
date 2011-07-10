/*
** util_string.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/src
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Mon Jun 20 16:23:55 2011 Julien Di Marco
** Last update Mon Jun 20 16:23:55 2011 Julien Di Marco
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

