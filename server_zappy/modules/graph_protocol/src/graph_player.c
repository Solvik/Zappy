/*
** graph_player.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 14 16:08:10 2011 seb
** Last update Wed Jul  6 20:18:21 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_player.h"
#include "tserver.h"

/* ppo numero_joueur X Y orientation */

bool graph_ppo(t_fds *client, char *cmd)
{
  char *id;
  char *to_send;
  unsigned int	x;
  unsigned int	y;
  unsigned int	o;

  strtok(cmd, " ");
  id = strtok(NULL, " ");
  if (!id || get_player_pos(atoi(id), &x, &y, &o) == false)
    {
      sends(client, "sbp");
      return (false);
    }
  if (asprintf(&to_send, "ppo %s %d %d %d", id, x, y, o) == -1)
    return (false);
  sends(client, to_send);
  free(to_send);
  return (true);
}

/* plv numero_joueur niveau */

bool graph_plv(t_fds *client, char *cmd)
{
  char *id;
  char *to_send;
  int	level;

  strtok(cmd, " ");
  id = strtok(NULL, " ");
  if (!id || (level = get_player_level(atoi(id))) == 0)
    {
      sends(client, "sbp");
      return (false);
    }
  if (asprintf(&to_send, "plv %s %d", id, level) == -1)
    return (false);
  sends(client, to_send);
  free(to_send);
  return (true);
}

/* pin numero_joueur X Y quantite_pierre quantite_bouffe */

bool graph_pin(t_fds *client, char *cmd)
{
  char *id;
  char *to_send;
  unsigned int x;
  unsigned int y;

  strtok(cmd, " ");
  id = strtok(NULL, " ");
  if (!id || get_player_pos(atoi(id), &x, &y, NULL) == false)
    {
      sends(client, "sbp");
      return (false);
    }
  if (asprintf(&to_send, "pin %s %d %d %d %d %d %d %d %d %d", id, x, y,
	       get_player_food(atoi(id)),
	       get_player_nbstones(atoi(id), LINEMATE),
	       get_player_nbstones(atoi(id), DERAUMERE),
	       get_player_nbstones(atoi(id), SIBUR),
	       get_player_nbstones(atoi(id), MENDIANE),
	       get_player_nbstones(atoi(id), PHIRAS),
	       get_player_nbstones(atoi(id), THYSTAME)) == -1)
    return (false);
  sends(client, to_send);
  free(to_send);
  return (true);
}
