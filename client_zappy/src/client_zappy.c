/*
** client_zappy.c for  in /Users/Lifely/Developer/project/Zappy/client_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:33:31 2011 Julien Di Marco
** Last update Tue Jul  5 19:21:04 2011 solvik blum
*/

#include	"client_zappy.h"

void		create_window(t_visu *p)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Can't init SDL. We're going to die\n");
      exit(EXIT_FAILURE);
    }
  SDL_EnableKeyRepeat(1, 1);
  SDL_WM_SetCaption("Zappy", NULL);
  p->sprite->grass = "images/monster_left.png";
}

void		connect_server(char *addr, int port)
{
  sends(truc, "GRAPHIC");
  // while on recoit, on traite selon cmd[0]
}

bool		client_zappy(char *addr, int port)
{
  t_visu	visu;

  create_window(&visu);
  connect_server(addr, port);
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
