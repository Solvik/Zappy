/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Thu Jul  7 20:24:57 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "player.h"
#include "server_zappy.h"
#include "tserver.h"

int		tr_x;
int		tr_y;
char		*text;

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
  int		dir;
  char		*to_send;

  dir = 0;
  to_send = NULL;
  new_x = (((t_player *)(((t_fds *)player)->data))->x + tr_x - get_map_width() / 2) % get_map_width();
  new_y = (((t_player *)(((t_fds *)player)->data))->y + tr_y - get_map_height() / 2) % get_map_height();
  hyp = sqrt(pow(-new_x ,2) + pow(-new_y, 2));
  adj = abs(new_x);
  angle = acos(adj / hyp);
  angle = (angle * 180) / 3.1415;
  angle = 90 - (int)angle;
  if (0 == new_x || 0 == new_y)
    {
      if (0 == new_y && new_x < 0)
	dir = get_sound_direction(1, ((t_player *)(((t_fds *)player)->data)));
      if (0 == new_y && new_x > 0)
	dir = get_sound_direction(5, ((t_player *)(((t_fds *)player)->data)));
      if (0 == new_x && new_y > 0)
	dir = get_sound_direction(3, ((t_player *)(((t_fds *)player)->data)));
      if (0 == new_x && new_y < 0)
	dir = get_sound_direction(7, ((t_player *)(((t_fds *)player)->data)));
    }
  else
    {
      if (new_x <= 0 && new_y >= 0)
	{
	  if (angle <= -25)
	    dir = get_sound_direction(3, ((t_player *)(((t_fds *)player)->data)));
	  else if (angle > -25 && angle <= -65)
	    dir = get_sound_direction(2, ((t_player *)(((t_fds *)player)->data)));
	  else
	    dir = get_sound_direction(1, ((t_player *)(((t_fds *)player)->data)));
	}
      else if (new_x <= 0 && new_y <= 0)
	{
	  if (angle >= -25)
	    dir = get_sound_direction(1, ((t_player *)(((t_fds *)player)->data)));
	  else if (angle < -25 && angle >= -65)
	    dir = get_sound_direction(8, ((t_player *)(((t_fds *)player)->data)));
	  else
	    dir = get_sound_direction(7, ((t_player *)(((t_fds *)player)->data)));
	}
      else if (new_x >= 0 && new_y >= 0)
	{
	  if (angle <= 25)
	    dir = get_sound_direction(3, ((t_player *)(((t_fds *)player)->data)));
	  else if (angle > 25 && angle <= 65)
	    dir = get_sound_direction(4, ((t_player *)(((t_fds *)player)->data)));
	  else
	    dir = get_sound_direction(5, ((t_player *)(((t_fds *)player)->data)));
	}
      else
	{
	  if (angle <= 25)
	    dir = get_sound_direction(7,((t_player *)(((t_fds *)player)->data)));
	  else if (angle > 25 && angle <= 65)
	    dir = get_sound_direction(6, ((t_player *)(((t_fds *)player)->data)));
	  else
	    dir = get_sound_direction(5, ((t_player *)(((t_fds *)player)->data)));
	}
    }
  send_format((t_fds *)player, "message %d,%s", dir, text);
}

int		zappy_broadcast(t_fds *client, char *cmd)
{
  t_module	*mod;
  t_bdata	*data;

  mod = get_module_by_name("Zappy Protocol");
  (void)strtok_r(cmd, " ", &text);
  if (!text)
    {
      sends(client, "ko");
      return (1);
    }
  tr_x = get_map_width() / 2 - player_data->x;
  tr_y = get_map_height() / 2 - player_data->y;
  foreach_list(mod->clients, send_broadcast);
  data = malloc(sizeof(t_bdata));
  data->ui1 = player_data->id;
  data->txt1 = strdup(text);
  event_relative_dispatch("Broadcast", (void *)data, 0);
  return (1);
}
