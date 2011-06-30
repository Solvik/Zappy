/*
** graph_map.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 18:51:14 2011 seb
** Last update Mon Jun 13 18:51:14 2011 seb
*/

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

/*
** TODO : Mettre le bon nombre de fonction dans le malloc
** getbox_nbstones(x, y, BOUFFE) - L: 47 - to replace 42
*/

bool graph_bct(t_fds *player, char *cmd)
{
  char *to_send;
  t_box *box;
  char *token;
  uint x;
  uint y;

  token = strtok(cmd, " ");
  x = atoi(strtok(NULL, " "));
  y = atoi(strtok(NULL, " "));
  box = get_box(x, y);
  asprintf(&to_send, "bct %d %d %d %d %d %d %d %d %d", x, y, 42,
	   getbox_nbstones(x, y, LINEMATE),
	   getbox_nbstones(x, y, DERAUMERE),
	   getbox_nbstones(x, y, SIBUR),
	   getbox_nbstones(x, y, MENDIANE),
	   getbox_nbstones(x, y, PHIRAS),
	   getbox_nbstones(x, y, THYSTAME));
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
