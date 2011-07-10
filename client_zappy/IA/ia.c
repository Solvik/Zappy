/*
** Ia.c for  in /home/carade_g/Zappy/client_zappy
** 
** Made by guillaume caradec
** Login   <carade_g@epitech.net>
** 
** Started on  Sun Jul 10 16:41:08 2011 guillaume caradec
** Last update Sun Jul 10 20:16:10 2011 guillaume caradec
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<stdio.h>

#include	"network.h"
#include	"client_zappy.h"
#include	"time_.h"
#include	"visu_func.h"

bool		danger(t_fds **pooler)
{
  char		*cmd;
  t_cmd		*inc_cmd;
  bool 		danger = false;
  int		eat;
  
  sends(*pooler, "inventaire");
  while ((cmd = getcmd(*pooler)))
    {
      eat = get_eat(cmd);
      printf ("Eat : %i\n", eat);
      if (eat < 3)
	{
	  sends(*pooler, "prend nourriture");
	  sends(*pooler, "droite");
	  sends(*pooler, "avance");
	  printf("DANGER !\n");
	  danger = true;
	}
      printf("%s\n", cmd);
      inc_cmd = parse_cmd(cmd);
      free_cmd(inc_cmd);
    } 
  return (danger);
}

void		live(t_fds **pooler)
{
  time__	tv;

  sends(*pooler, "A");
  while (1)
    {
      sleep(1);
      
      pool(pooler, timeval_(&tv, 0.001));
      if (!danger(pooler))
	sends(*pooler, "avance");
    }
}

bool		ia(int ac, char **av)
{
  t_fds		*pooler;

  pooler = NULL;
  if (ac > 2)
    {
      add_co(&pooler, av[1], atoi(av[2]));
      live(&pooler);
    }
  return (true);
}

int		main(int ac, char **av)
{
  return (ia(ac, av) ? EXIT_SUCCESS : EXIT_FAILURE);
}
