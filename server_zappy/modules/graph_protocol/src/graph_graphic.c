/*
** graph_graphic.c for  in /home/seb/git/Zappy/server_zappy/modules/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 28 15:12:30 2011 seb
** Last update Wed Jul  6 16:49:12 2011 ramnes
*/

#include <stdlib.h>

#include "graph_egg.h"
#include "graph_graphic.h"
#include "graph_map.h"
#include "graph_player.h"
#include "graph_team.h"
#include "graph_time.h"

/*
**   //graph_enw(client, NULL); - l: 24
*/

bool graph_graphic(t_fds *client, char *_)
{
  (void)_;
  graph_sgt(client, NULL);
  graph_msz(client, NULL);
  graph_mct(client, NULL);
  graph_tna(client, NULL);
  return (true);
}
