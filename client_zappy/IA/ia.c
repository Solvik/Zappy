/*
** Ia.c for  in /home/carade_g/Zappy/client_zappy
** 
** Made by guillaume caradec
** Login   <carade_g@epitech.net>
** 
** Started on  Sun Jul 10 16:41:08 2011 guillaume caradec
** Last update Sun Jul 10 23:07:08 2011 guillaume caradec
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<stdio.h>
#include	<stdbool.h>
#include	<time.h>

#include	"network.h"
#include	"client_zappy.h"
#include	"time_.h"
#include	"ia.h"

int		move(t_fds **pooler)
{
  char		*cmd;
  int		eat;
  
  while ((cmd = getcmd(*pooler)))
    {
      if (!strcmp(cmd, "mort"))
	return (0);
      eat = get_eat(cmd);
      if (eat < 7)
      	{
      	  sends(*pooler, "prend nourriture");
      	  if (rand() % 10 < 5)
      	    sends(*pooler, "droite");
      	  else
      	    sends(*pooler, "gauche");
      	}
      sends(*pooler, "avance");
      free(cmd);
    }
  return (1);
}

void		live(t_fds **pooler, char *team)
{
  time__	tv;

  sends(*pooler, team);
  while (1)
    {
      pool(pooler, timeval_(&tv, 0.001));
      sends(*pooler, "avance");
      if (!move(pooler) || !fds_alive(*pooler))
	{
	  printf("OH NO :(\n");
	  exit(-1);
	}
    }
}

bool		ia(int ac, char **av)
{
  t_fds		*pooler;

  pooler = NULL;
  if (ac == 4)
    {
      add_co(&pooler, av[1], atoi(av[2]));
      live(&pooler, av[3]);
    }
  return (true);
}

int		main(int ac, char **av)
{
  srand(time(NULL));
  return (ia(ac, av) ? EXIT_SUCCESS : EXIT_FAILURE);
}
