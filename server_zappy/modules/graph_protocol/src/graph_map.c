/*
** graph_map.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stone.h"
#include "tserver.h"
#include "graph_map.h"

bool graph_msz(t_fds *client, char *cmd __attribute__((unused)))
{
  sendf(client, "msz %u %u", get_map_width(), get_map_height());
  return (true);
}

bool graph_bct(t_fds *client, char *cmd)
{
  char *x;
  char *y;

  strtok(cmd, " ");
  x = strtok(NULL, " ");
  y = strtok(NULL, " ");
  if (!x || !y)
    {
      sends(client, "sbp");
      return (false);
    }
  sendf(client, "bct %d %d %d %d %d %d %d %d %d", atoi(x), atoi(y),
	get_box_nbfood(atoi(x), atoi(y)),
	get_box_nbstones(atoi(x), atoi(y), LINEMATE),
	get_box_nbstones(atoi(x), atoi(y), DERAUMERE),
	get_box_nbstones(atoi(x), atoi(y), SIBUR),
	get_box_nbstones(atoi(x), atoi(y), MENDIANE),
	get_box_nbstones(atoi(x), atoi(y), PHIRAS),
	get_box_nbstones(atoi(x), atoi(y), THYSTAME));
  return (true);
}

bool graph_mct(t_fds *client, char *cmd __attribute__((unused)))
{
  char *msg;
  uint x;
  uint y;

  x = 0;
  y = 0;
  while (x < get_map_width())
    {
      while (y < get_map_height())
	{
	  if (asprintf(&msg, "bct %d %d", x, y) == -1)
	    return (false);
	  graph_bct(client, msg);
	  free(msg);
	  y++;
	}
      y = 0;
      x++;
    }
  return (true);
}
