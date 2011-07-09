/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sat Jul  9 02:41:04 2011 ramnes
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"napi.h"

#include	"voir.h"
#include	"zappy_protocol.h"

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
  t_generic	*data;
  char		*obj;

  if (!(data = malloc(sizeof(*data))))
    return (false);
  strtok(cmd, " \t");
  obj = strtok(NULL, " \t");
  if (obj)
    {
      if (prendre_action(player_data->x, player_data->y, obj))
	{
	  data->ui1 = player_data->id;
	  data->ui2 = 0; /* ramnes: TODO s/0/numéro de ressource/ */
	  event_relative_dispatch("TakeItem", data, 0);
	  sends(client, "ok");
	  return (1);
	}
    }
  sends(client, "ko");
  return (0);
}
