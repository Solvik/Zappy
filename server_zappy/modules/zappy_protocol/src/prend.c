/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Thu Jun 30 09:46:36 2011 solvik blum
*/

#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "map.h"
#include "voir.h"
#include "server_zappy.h"

e_stone		is_stone(char *str)
{
  int		i;

  i = 0;
  while (i < size_stone)
    {
      if (!strcmp(str, &(gl_ressource_name[i].str[1])))
	return (gl_ressource_name[i].stone);
      i++;
    }
  return (NONE);
}

static bool	prendre_action(int x, int y, char *obj)
{
  t_box		*map;
  e_stone	stone;

  map = get_map();
  if ((stone = is_stone(obj)) != NONE)
    {
      if (setbox_delstone(x, y, stone, 1) == true)
	return (true);
      else
	return (false);
    }
  else if (!strcmp(obj, "nourriture"))
    {
      /* if (setbox_delfood(x, y, 1) == true) */
      /* 	return (true); */
      /* else */
      /* 	return (false); */
      return (true);
    }
  else
    return (false);
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
