/*
** graph_time.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Thu Jun 16 17:05:11 2011 seb
** Last update Thu Jun 30 06:42:12 2011 Sebastien Blot
*/

#include <stdio.h>

#include <stdbool.h>
#include "tserver.h"
#include "graph_time.h"

/*
** sgt unite_temps
** get_Server_time() - l: 25
*/

bool graph_sgt(t_fds *client, char *_)
{
  char *to_send;

  (void)_;
  to_send = NULL;
  asprintf(&to_send, "sgt %f", get_delay());
  sends(client, to_send);
  free(to_send);
  return (true);
}

/*
** sgt unite_temps
*/

bool graph_sst(t_fds *__, char *_)
{
  (void)__;
  (void)_;
  return (true);
}
