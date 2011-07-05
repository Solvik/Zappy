/*
** inventaire.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Tue Jun 14 17:42:10 2011 solvik blum
** Last update Mon Jul  4 01:19:27 2011 solvik blum
*/

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stone.h"
#include "player.h"
#include "server_zappy.h"

#include "tserver.h"

int		zappy_inventaire(t_fds *client, char *cmd)
{
  int		r;
  char		*str;

  (void)cmd;
  r = asprintf(&str, "{"
	       "nourriture %u,"
	       "linemate %u,"
	       "deraumere %u,"
	       "sibur %u,"
	       "mendiane %u,"
	       "phiras %u,"
	       "thystame %u"
	       "}",
	       player_data->food,
	       get_box_nbstones_by_player(player_data, LINEMATE),
	       get_box_nbstones_by_player(player_data, DERAUMERE),
	       get_box_nbstones_by_player(player_data, SIBUR),
	       get_box_nbstones_by_player(player_data, MENDIANE),
	       get_box_nbstones_by_player(player_data, PHIRAS),
	       get_box_nbstones_by_player(player_data, THYSTAME));
  sends(client, str);
  if (str)
    free(str);
  return (1);
}
