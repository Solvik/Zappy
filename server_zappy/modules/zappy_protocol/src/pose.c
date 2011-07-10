/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sun Jul 10 14:11:54 2011 guillaume gelin
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
      player->food -= 1;
      if (set_box_addfood(player->x, player->y, 1))
	return (true);
      else
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
