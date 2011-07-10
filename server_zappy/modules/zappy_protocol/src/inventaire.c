/*
** inventaire.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include	"napi.h"

#include	"zappy_protocol.h"

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
