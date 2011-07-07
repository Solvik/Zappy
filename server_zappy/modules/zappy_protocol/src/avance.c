/*
** avance.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 15:55:53 2011 solvik blum
** Last update Thu Jul  7 20:53:57 2011 ramnes
*/

#include	<stdlib.h>
#include	"napi.h"
#include	"map.h"
#include	"player.h"
#include	"server_zappy.h"
#include	"tserver.h"

typedef struct	s_avance
{
  int		(*func)();
  e_direction	dir;
}		t_avance;

static int	avance_haut(t_fds *client)
{
  player_data->y = (player_data->y - 1) % get_map_height();
  return (1);
}

static int	avance_bas(t_fds *client)
{
  player_data->y = (player_data->y + 1) % get_map_height();
  return (1);
}

static int	avance_droite(t_fds *client)
{
  player_data->x = (player_data->x + 1) % get_map_width();
  return (1);
}

static int	avance_gauche(t_fds *client)
{
  player_data->x = (player_data->x - 1) % get_map_width();
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
  uint		i;
  uint		size;

  (void)cmd;
  i = -1;
  size = sizeof(gl_tab) / sizeof(t_avance);
  while (++i < size)
    if (player_data->direction == gl_tab[i].dir)
      {
	gl_tab[i].func(client);
	sends(client, "ok");
	event_relative_dispatch("PlayerMove", client, 0);
	return (1);
      }
  return (0);
}
