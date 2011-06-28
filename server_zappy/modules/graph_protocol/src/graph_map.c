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
#include "tserver.h"
#include "graph_map.h"

bool handle_msz(t_fds *player, char *cmd)
{
  char *to_send;

  to_send = NULL;
  asprintf(&to_send, "msz %u %u", get_map_width(), get_map_height());
  sends(player, to_send);
  free(to_send);
  return true;
}

bool handle_bct(t_fds *player, char *cmd)
{
  uint x;
  uint y;
  char *to_send;
  t_box *box;

  x = 0;
  to_send = NULL;
  while (x < get_map_width())
    {
      y = 0;
      while (y < get_map_height())
	{
	  box = get_box(x, y);
	  asprintf(&to_send, "bct %d %d %d %d %d %d %d %d %d", /* remplacer par get_stone_machin() */x, y, 1,1,1,1,1,1,1);
	  sends(player, to_send);
	  free(to_send);
	  y++;
	}
      x++;
    }
  return true;
}

bool handle_mct(t_fds *player,char *cmd)
{
  (void)player;
  /*
    On envoie le contenu de toute les cases de la map
    => appeler handle_case_content pour toutes les cases
   */
  return true;
}
