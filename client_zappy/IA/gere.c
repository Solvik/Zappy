/*
** gere.c for Zappy in ./client_zappy/IA
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<stdio.h>

#include	"network.h"
#include	"client_zappy.h"
#include	"time_.h"

int		get_eat(char *cmd)
{
  char		*s;

  (void)strtok(cmd, " ,");
  s = strtok(NULL,  " ,");
  if (s)
    return (atoi(s));
  return (0);
}

t_cmd		*parse_cmd(char *str)
{
  int		len;
  t_cmd		*s;
  char		*ret;

  len = 0;
  if (!(s = malloc(sizeof(*s))))
    return (NULL);
  if (!(s->argv = malloc(sizeof(*(s->argv)))))
    return (NULL);
  if ((ret = strtok(str, " \t")))
    {
      if (!(s->argv = realloc(s->argv, sizeof(*(s->argv)) * (len + 1))))
	return (NULL);
      s->argv[len++] = strdup(ret);
    }
  while ((ret = strtok(NULL, " \t")))
    {
      if (!(s->argv = realloc(s->argv, sizeof(*(s->argv)) * (len + 1))))
	return (NULL);
      s->argv[len++] = strdup(ret);
    }
  s->argc = len;
  return (s);
}

void			free_cmd(t_cmd *c)
{
  int			i;

  i = 0;
  while (c && c->argv && i < c->argc)
    free(c->argv[i++]);
  free(c->argv);
  if (c)
    free(c);
}

