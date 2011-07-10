/*
** broadcast.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "napi.h"
#include "zappy_protocol.h"

struct s_info
{
  int		tr_x;
  int		tr_y;
  int		dir;
  char		*text;
}		info;

static float	get_angle(int new_x, int new_y)
{
  float		hyp;
  float		adj;
  float		angle;

  hyp = sqrt(pow(-new_x, 2) + pow(-new_y, 2));
  adj = abs(new_x);
  angle = acos(adj / hyp);
  angle = (angle * 180) / 3.1415;
  angle = 90 - (int)angle;
  angle = abs(angle);

  return (angle);
}

static void	choose_dir(int new_x, int new_y, void *player, int angle)
{
  if (0 == new_x || 0 == new_y)
    {
      if (0 == new_y && new_x < 0)
	info.dir = get_sound_direction(1, ((t_player *)(((t_fds *)player)->data)));
      if (0 == new_y && new_x > 0)
	info.dir = get_sound_direction(5, ((t_player *)(((t_fds *)player)->data)));
      if (0 == new_x && new_y > 0)
	info.dir = get_sound_direction(3, ((t_player *)(((t_fds *)player)->data)));
      if (0 == new_x && new_y < 0)
	info.dir = get_sound_direction(7, ((t_player *)(((t_fds *)player)->data)));
    }
  else
    {
      if (new_x > 0 && new_y < 0)
	info.dir = first_quad(angle, player);
      else if (new_x < 0 && new_y < 0)
	info.dir = second_quad(angle, player);
      else if (new_x > 0 && new_y > 0)
	info.dir = third_quad(angle, player);
      else if (new_x < 0 && new_y > 0)
	fourth_quad(angle, player);
    }
}

static void	send_broadcast(void *player, void *dest)
{
  int		new_x;
  int		new_y;
  float		angle;
  t_fds		*client;

  client = (t_fds *)player;
  if (player_data == (t_player *)dest)
    {
      sends(client, "ok");
      return;
    }
  new_x = (((t_player *)(((t_fds *)player)->data))->x + info.tr_x -
	   get_map_width() / 2);
  new_y = (((t_player *)(((t_fds *)player)->data))->y + info.tr_y -
	   get_map_height() / 2);
  angle = get_angle(new_x, new_y);
  if (abs(new_x) > get_map_width() / 2)
    new_x > 0 ? (new_x -= get_map_width()) : (new_x += get_map_width());
  if (abs(new_y) > get_map_height() / 2)
    new_y > 0 ? (new_y -= get_map_height()) : (new_y += get_map_height());
  choose_dir(new_x, new_y, player, angle);
  sendf((t_fds *)player, "message %d,%s", info.dir, info.text);
}

int		zappy_broadcast(t_fds *client, char *cmd)
{
  t_module	*mod;
  t_generic	data;

  mod = get_module_by_name("Zappy Protocol");
  (void)strtok_r(cmd, " ", &info.text);
  if (!info.text)
    {
      sends(client, "ko");
      return (1);
    }
  info.tr_x = get_map_width() / 2 - player_data->x;
  info.tr_y = get_map_height() / 2 - player_data->y;
  foreach_arg_list(mod->clients, send_broadcast, player_data);
  data.ui1 = player_data->id;
  data.txt1 = strdup(info.text);
  event_relative_dispatch("Broadcast", &data, 0);
  free(data.txt1);
  return (0);
}
