/*
** pose.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"napi.h"

#include	"voir.h"
#include	"zappy_protocol.h"

static bool	pose_action(t_player *player, char *obj)
{
  e_stone	stone;

  if ((stone = is_stone(obj)) != NONE)
    {
      if (!set_player_delstone(player, stone, 1) ||
	  !set_box_addstone(player->x, player->y, stone, 1))
	return (false);
    }
  else if (!strcasecmp(obj, "nourriture") && player->food > 0)
    {
      if (!(set_player_delfood(player->id, 1)) ||
	  !(set_box_addfood(player->x, player->y, 1)))
	return (false);
    }
  else
    return (false);
  return (true);
}

int		zappy_pose(t_fds *client, char *cmd)
{
  t_player	*p;
  t_generic	data;
  char		*obj;

  if (!client || !(p = *(t_player**)client) || !cmd ||
      !(strtok(cmd, " \t")) || !(obj = strtok(NULL, " \t")) ||
      !pose_action(p, obj))
    {
      sends(client, "ko");
      return (false);
    }
  data.ui1 = get_ressource_id(obj);
  data.client = client;
  event_relative_dispatch("DropItem", &data, 0);
  sends(client, "ok");
  return (0);
}
