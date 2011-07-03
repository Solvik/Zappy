/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Wed Jun 29 17:12:59 2011 solvik blum
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "player.h"
#include "server_zappy.h"
#include "tserver.h"

int		tr_x;
int		tr_y;

static void	send_broadcast(void *player)
{
  int		new_x;
  int		new_y;
  float		hyp;
  float		adj;
  float		angle;

  new_x = ((t_player *)(player))->x - tr_x;
  new_y = ((t_player *)(player))->y - tr_y;
  hyp = sqrt(pow(-new_x ,2) + pow(-new_y, 2));
  adj = abs(new_x);
  angle = acos(adj / hyp);
  angle = (angle * 180) / 3.1415;
  angle = 90 - angle;
  printf("angle = %f\n", angle);
}

int		zappy_broadcast(t_fds *client, char *cmd)
{
  uint		x;
  uint		y;
  char		*text;
  t_list	*players;

  (void)strtok(cmd, " ");
  text = strtok(NULL, " ");

  tr_x = get_map_width() / 2 - player_data->x;
  tr_y = get_map_height() / 2 - player_data->y;

  x = 0;
  printf("LOLOLOLOL\n");
  while (x < get_map_width())
    {
      y = 0;
      while (y < get_map_height())
	{
	  players = get_players(x, y);
	  if (players)
	    foreach_list(players, send_broadcast);
	  y++;
	}
      x++;
    }
  sends(client, "ta mere la chienne");
  return (1);
}
