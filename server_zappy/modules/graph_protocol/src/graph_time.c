/*
** graph_time.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Thu Jun 16 17:05:11 2011 seb
** Last update Wed Jul  6 20:21:12 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>

#include <stdbool.h>
#include <string.h>
#include "tserver.h"
#include "graph_time.h"

/* sgt unite_temps */

bool graph_sgt(t_fds *client, char *cmd __attribute__((unused)))
{
  char *to_send;

  if (asprintf(&to_send, "sgt %f", get_delay()) == -1)
    return (false);
  sends(client, to_send);
  free(to_send);
  return (true);
}

/* sgt unite_temps */

bool graph_sst(t_fds *client, char *cmd)
{
  char *delay;

  strtok(cmd, " ");
  delay = strtok(NULL, " ");
  if (!delay)
    {
      sends(client, "sbp");
      return (false);
    }
  set_delay(atof(delay));
  graph_sgt(client, cmd);
  return (true);
}
