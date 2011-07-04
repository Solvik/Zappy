/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Mon Jul  4 01:23:02 2011 solvik blum
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"player.h"
#include	"map.h"
#include	"voir.h"
#include	"server_zappy.h"

#include	"tserver.h"

static bool	prendre_action(int x, int y, char *obj)
{
  t_box		*map;
  e_stone	stone;

  map = get_map();
  if ((stone = is_stone(obj)) != NONE)
    {
      if (!set_box_delstone(x, y, stone, 1))
	return (false);
    }
  else if (!strcasecmp(obj, "nourriture"))
    {
      if (!set_box_delfood(x, y, 1))
	return (false);
    }
  else
    return (false);
  return (true);
}

int		zappy_prend(t_fds *client, char *cmd)
{
  char		*obj;

  strtok(cmd, " \t");
  obj = strtok(NULL, " \t");
  if (obj)
    {
      if (prendre_action(player_data->x, player_data->y, obj))
	{
	  sends(client, "ok");
	  return (1);
	}
    }
  sends(client, "ko");
  return (0);
}
