/*
** avance.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 15:55:53 2011 solvik blum
** Last update Mon Jun 13 17:31:58 2011 solvik blum
*/

#include <stdlib.h>

#include "player.h"
#include "server_zappy.h"


typedef struct	s_avance
{
  int		(*func)();
  e_direction	dir;
}		t_avance;

static int	avance_haut(t_player *player)
{
}

static int	avance_bas(t_player *player)
{
}

static int	avance_droite(t_player *player)
{
}

static int	avance_gauche(t_player *player)
{
}

static const t_avance	gl_tab[4] =
  {
    {avance_haut, NORTH},
    {avance_bas, SOUTH},
    {avance_droite, EAST},
    {avance_gauche, WEST},
  };

int		zappy_avance(t_player *player)
{
}
