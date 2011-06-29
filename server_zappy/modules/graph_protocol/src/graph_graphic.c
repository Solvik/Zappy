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

bool graph_graphic(t_fds *client, char *cmd)
{
  graph_sgt(client, NULL);
  graph_msz(client, NULL);
  graph_mct(client, NULL);
  graph_tna(client, NULL);
  graph_pnw(client, NULL);
  //graph_enw(client, NULL);
  return true;
}
