/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sun Jul  3 17:24:24 2011 solvik blum
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"player.h"
#include	"map.h"
#include	"voir.h"
#include	"server_zappy.h"

#include	"tserver.h"

static bool	pose_action(t_player *player, char *obj)
{
  e_stone	stone;

  if ((stone = is_stone(obj)) != NONE)
    {
      if (!setbox_addstone(player->x, player->y, stone, 1) ||
	  !setplayer_delstone(player, stone, 1))
	return (false);
    }
  else if (!strcmp(obj, "nourriture"))
    {
      player->life -= 1;
      if (setbox_addfood(player->x, player->y, 1))
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
  char		*obj;

  strtok(cmd, " \t");
  obj = strtok(NULL, " \t");
  if (obj)
    {
      if (pose_action(player_data, obj))
	{
	  sends(client, "ok");
	  return (1);
	}
    }
  sends(client, "ko");
  return (0);
}
