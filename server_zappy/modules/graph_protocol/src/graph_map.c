/*
** graph_map.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 18:51:14 2011 seb
** Last update Tue Jul  5 16:05:44 2011 guillaume gelin
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stone.h"
#include "tserver.h"
#include "graph_map.h"

bool graph_msz(t_fds *player, char *_)
{
  char *to_send;

  (void)_;
  to_send = NULL;
  asprintf(&to_send, "msz %u %u", get_map_width(), get_map_height());
  sends(player, to_send);
  free(to_send);
  return (true);
}

bool graph_bct(t_fds *player, char *cmd)
{
  char *to_send;
  t_box *box;
  char *token;
  char *x;
  char *y;

  token = strtok(cmd, " ");
  x = strtok(NULL, " ");
  y = strtok(NULL, " ");
  if (!x || !y)
	return (false);
  box = get_box(atoi(x), atoi(y));
  asprintf(&to_send, "bct %d %d %d %d %d %d %d %d %d", atoi(x), atoi(y), 42 /* à modifier par la bouffe */,
		   get_box_nbstones(atoi(x), atoi(y), LINEMATE),
		   get_box_nbstones(atoi(x), atoi(y), DERAUMERE),
		   get_box_nbstones(atoi(x), atoi(y), SIBUR),
		   get_box_nbstones(atoi(x), atoi(y), MENDIANE),
		   get_box_nbstones(atoi(x), atoi(y), PHIRAS),
		   get_box_nbstones(atoi(x), atoi(y), THYSTAME));
  sends(player, to_send);
  free(to_send);
  return (true);
}

bool graph_mct(t_fds *player, char *_)
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
	  asprintf(&msg, "bct %d %d", x, y);
	  graph_bct(player, msg);
	  free(msg);
	  y++;
	}
      x++;
    }
  return (true);
}
