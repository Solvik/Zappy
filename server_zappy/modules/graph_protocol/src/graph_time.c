/*
** graph_time.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Thu Jun 16 17:05:11 2011 seb
** Last update Thu Jun 16 17:05:11 2011 seb
*/

#include <stdbool.h>
#include "graph_time.h"


bool graph_sgt(t_fds *client, char *cmd)
{

  char *to_send;

  to_send = NULL;
  asprintf(&to_send, "sgt %d", /* get_Server_time() */ 10);
  sends(client, to_send);
  free(to_send);
  /*
   * sgt unite_temps
   */
  return true;
}

bool graph_sst(t_fds *client, char *cmd)
{
  (void)client;
  /*
   * sgt unite_temps
   */
  return true;
}
