/*
** avance.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 15:55:53 2011 solvik blum
** Last update Wed Jun 29 11:05:06 2011 solvik blum
*/

#include <stdlib.h>

#include "player.h"
#include "server_zappy.h"

typedef struct	s_avance
{
  int		(*func)();
  e_direction	dir;
}		t_avance;

static int	avance_haut(t_fds *client)
{
  player_data->y--;
  return (1);
}

static int	avance_bas(t_fds *client)
{
  player_data->y++;
  return (1);
}

static int	avance_droite(t_fds *client)
{
  player_data->x++;
  return (1);
}

static int	avance_gauche(t_fds *client)
{
  if (player_data->x == 1)
    player_data->x--;
  return (1);
}

static const t_avance	gl_tab[4] =
  {
    {avance_haut, NORTH},
    {avance_bas, SOUTH},
    {avance_droite, EAST},
    {avance_gauche, WEST},
  };

int		zappy_avance(t_fds *client, char *cmd)
{
  unsigned int	i;
  unsigned int	size;

  (void)cmd;
  i = 0;
  size = sizeof(gl_tab) / sizeof(t_avance);
  while (i < size)
    {
      if (player_data->direction == gl_tab[i].dir)
	{
	  gl_tab[i].func(client);
	  sends(client, "ok\n");
	  return (1);
	}
    }
  return (0);
}
