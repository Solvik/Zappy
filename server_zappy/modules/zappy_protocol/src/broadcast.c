/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Mon Jul  4 17:05:52 2011 Sebastien Blot
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "player.h"
#include "server_zappy.h"
#include "tserver.h"

int		tr_x;
int		tr_y;

/* 12:42 < _Natas> Sud : + 2 % 8 | Ouest : + 4 % 8 | Nord : + 6 % 8 */


static int get_sound_direction(int n, void *player)
{
  if (((t_player *)(player))->direction == SOUTH)
	return ((n + 2) % 8 + 1);
  else if (((t_player *)(player))->direction == WEST)
	return ((n + 4) % 8 + 1);
  else if (((t_player *)(player))->direction == NORTH)
	return ((n + 6) % 8 + 1);
  else
	return (n);
}

static void	send_broadcast(void *player)
{
  int		new_x;
  int		new_y;
  float		hyp;
  float		adj;
  float		angle;
  int			dir;

  new_x = (((t_player *)(player))->x + tr_x - get_map_width() / 2) % get_map_width();
  new_y = (((t_player *)(player))->y + tr_y - get_map_height() / 2) % get_map_height();
  printf("player_x = %d player_y = %d new_x = %d new_y = %d\n", ((t_player *)(player))->x,((t_player *)(player))->y, new_x, new_y);
  printf("translation x %d translation y %d\n", tr_x, tr_y);
  hyp = sqrt(pow(-new_x ,2) + pow(-new_y, 2));
  adj = abs(new_x);
  angle = acos(adj / hyp);
  angle = (angle * 180) / 3.1415;
  angle = 90 - (int)angle;
  printf("angle = %f\n", angle);
  if (0 == new_x || 0 == new_y)
    {
      if (0 == new_y && new_x < 0)
		dir = get_sound_direction(1, player);
      if (0 == new_y && new_x > 0)
		dir = get_sound_direction(5, player);
      if (0 == new_x && new_y > 0)
		dir = get_sound_direction(3, player);
      if (0 == new_x && new_y < 0)
		dir = get_sound_direction(7, player);
    }
  else
    {
      if (new_x <= 0 && new_y >= 0)
		{
		  if (angle <= -25)
			dir = get_sound_direction(3, player);
		  else if (angle > -25 && angle <= -65)
		    dir = get_sound_direction(2, player);
		  else
			dir = get_sound_direction(1, player);
		}
      else if (new_x <= 0 && new_y <= 0)
		{
		  if (angle >= -25)
			dir = get_sound_direction(1, player);
		  else if (angle < -25 && angle >= -65)
			dir = get_sound_direction(8, player);
		  else
			dir = get_sound_direction(7, player);
		}
      else if (new_x >= 0 && new_y >= 0)
		{
		  if (angle <= 25)
			dir = get_sound_direction(3, player);
		  else if (angle > 25 && angle <= 65)
			dir = get_sound_direction(4, player);
		  else
			dir = get_sound_direction(5, player);
		}
      else
		{
		  if (angle <= 25)
			dir = get_sound_direction(7, player);
		  else if (angle > 25 && angle <= 65)
			dir = get_sound_direction(6, player);
		  else
			dir = get_sound_direction(5, player);
		}
	}
}

int		zappy_broadcast(t_fds *client, char *cmd)
{
  uint		x;
  uint		y;
  char		*text;
  t_list	*players;
  t_module *this;

  this = get_module_by_name("Zappy Protocol");
  printf("%s\n", this->name);
  strtok(cmd, " ");
  text = strtok(NULL, " ");
  if (!text)
  	{
  	  sends(client, "ko");
  	  return (1);
  	}
  tr_x = get_map_width() / 2 - player_data->x;
  tr_y = get_map_height() / 2 - player_data->y;
  x = 0;
  while (x < get_map_width())
  	{
  	  y = 0;
  	  while (y < get_map_height())
  		{
  		  if ((players =  get_box_players(x, y)))
  			foreach_list(players, send_broadcast);
  		  y++;
  		}
  	  x++;
  	}
  return (1);
}
