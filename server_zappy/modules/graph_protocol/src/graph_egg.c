/*
** graph_egg.c for  in /home/seb/git/Zappy/server_zappy/modules/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 28 15:50:41 2011 seb
** Last update Tue Jun 28 15:50:41 2011 seb
*/

#include "graph_egg.h"

bool handle_enw(t_fds *client, char *cmd)
{
  sends(client, "enw 0 1 1 1");
}
