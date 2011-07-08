/*
** graph_map.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 18:51:14 2011 seb
** Last update Fri Jul  8 06:31:49 2011 ramnes
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
