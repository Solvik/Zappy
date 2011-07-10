/*
** gere.c for  in /home/carade_g/Zappy/client_zappy/IA
** 
** Made by guillaume caradec
** Login   <carade_g@epitech.net>
** 
** Started on  Sun Jul 10 18:37:56 2011 guillaume caradec
** Last update Sun Jul 10 23:06:03 2011 guillaume caradec
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

