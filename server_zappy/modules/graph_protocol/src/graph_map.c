/*
** graph_map.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 18:51:14 2011 seb
** Last update Wed Jul  6 20:12:16 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stone.h"
#include "tserver.h"
#include "graph_map.h"

bool graph_msz(t_fds *client, char *_)
{
  char *to_send;

  (void)_;
  to_send = NULL;
  if (asprintf(&to_send, "msz %u %u",
	       get_map_width(),
	       get_map_height()) == -1)
    return (false);
  sends(client, to_send);
  free(to_send);
  return (true);
}

bool graph_bct(t_fds *client, char *cmd)
{
  char *to_send;
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
  if (asprintf(&to_send, "bct %d %d %d %d %d %d %d %d %d", atoi(x), atoi(y),
	       get_box_nbfood(atoi(x), atoi(y)),
	       get_box_nbstones(atoi(x), atoi(y), LINEMATE),
	       get_box_nbstones(atoi(x), atoi(y), DERAUMERE),
	       get_box_nbstones(atoi(x), atoi(y), SIBUR),
	       get_box_nbstones(atoi(x), atoi(y), MENDIANE),
	       get_box_nbstones(atoi(x), atoi(y), PHIRAS),
	       get_box_nbstones(atoi(x), atoi(y), THYSTAME)) == -1)
    return (false);
  sends(client, to_send);
  free(to_send);
  return (true);
}

bool graph_mct(t_fds *client, char *_)
{
  uint x;
  uint y;
  char *msg;
  char *to_send;

  (void)_;
  x = 0;
  to_send = NULL;
  msg = NULL;
  while (x < get_map_width())
    {
      y = 0;
      while (y < get_map_height())
	{
	  if (asprintf(&msg, "bct %d %d", x, y) == -1)
	    return (false);
	  graph_bct(client, msg);
	  free(msg);
	  y++;
	}
      x++;
    }
  return (true);
}
