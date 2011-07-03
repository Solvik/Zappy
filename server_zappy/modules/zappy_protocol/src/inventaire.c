/*
** inventaire.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Tue Jun 14 17:42:10 2011 solvik blum
** Last update Sun Jul  3 17:24:50 2011 solvik blum
*/

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stone.h"
#include "itoa.h"
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
	       player_data->life,
	       getbox_nbstones_by_player(player_data, LINEMATE),
	       getbox_nbstones_by_player(player_data, DERAUMERE),
	       getbox_nbstones_by_player(player_data, SIBUR),
	       getbox_nbstones_by_player(player_data, MENDIANE),
	       getbox_nbstones_by_player(player_data, PHIRAS),
	       getbox_nbstones_by_player(player_data, THYSTAME));
  sends(client, str);
  if (str)
    free(str);
  return (1);
}
