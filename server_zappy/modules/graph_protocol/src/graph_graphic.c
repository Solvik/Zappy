/*
** graph_graphic.c for  in /home/seb/git/Zappy/server_zappy/modules/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 28 15:12:30 2011 seb
** Last update Tue Jun 28 15:12:30 2011 seb
*/

#include <stdlib.h>
#include "graph_graphic.h"

bool handle_graphic(t_fds *client, char *cmd)
{
  handle_sgt(client, NULL);
  handle_msz(client, NULL);
  handle_mct(client, NULL);
  handle_tna(client, NULL);
  handle_pnw(client, NULL);
  //handle_enw(client, NULL);
  return true;
}
