/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Wed Jun 29 17:47:37 2011 solvik blum
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "map.h"
#include "voir.h"
#include "server_zappy.h"

#include "tserver.h"

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

/*
** l: 58
** if (setbox_delfood(x, y, 1) == true)
** 	return (true);
** else
** return (false);
*/

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
    return (true);
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
