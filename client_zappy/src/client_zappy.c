/*
** client_zappy.c for  in /Users/Lifely/Developer/project/Zappy/client_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:33:31 2011 Julien Di Marco
** Last update Wed Jul  6 01:15:03 2011 solvik blum
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<stdio.h>

#include	"network.h"
#include	"client_zappy.h"

void		create_window(t_visu *p)
{
  (void)p;
  /* if (SDL_Init(SDL_INIT_VIDEO) == -1) */
  /*   { */
  /*     fprintf(stderr, "Can't init SDL. We're going to die\n"); */
  /*     exit(EXIT_FAILURE); */
  /*   } */
  /* SDL_EnableKeyRepeat(1, 1); */
  /* SDL_WM_SetCaption("Zappy", NULL); */
  /* p->sprite->grass = "images/monster_left.png"; */
}

void		handle_event(t_fds *pooler, t_visu *v)
{
  char		*cmd;
  t_cmd		*inc_cmd;

  while (1)
    {
      pool(&pooler, NULL);
      if (!pooler || (pooler && pooler->fd == -1))
	break;
      while ((cmd = getcmd(pooler)))
	{
	  inc_cmd = parse_cmd(cmd);
	  if (!gere_cmd(pooler, inc_cmd, v))
	    fprintf(stderr, "error unknown or wrong cmd %s\n", cmd);
	  /* free_cmd(inc_cmd); */
	}
      printf("lol\n");
    }
  // while on recoit, on traite selon cmd[0]
}

bool		client_zappy(int ac, char *av[])
{
  t_visu	visu;
  t_fds		*pooler;

  pooler = NULL;
  if (ac > 2)
    {
      create_window(&visu);
      add_co(&pooler, av[1], atoi(av[2]));
      handle_event(pooler, &visu);
    }
  // event (souris)
  // send > GRAPHIC
  // on recupere les infos
  // msz X Y > taille map
  // sgt T > temps
  // "bct 0 0 q q q q q q q\n" >> contenu de chaque case
  // tna N >> nom de chaque equipe
  // "pnw #n X Y O L N\n" >> connexion d'un nouveau joueur
  // oeuf pondu >> ok
  return (true);
}
