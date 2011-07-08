/*
** graph_time.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Thu Jun 16 17:05:11 2011 seb
** Last update Fri Jul  8 06:22:46 2011 ramnes
*/

#include <stdbool.h>
#include <string.h>
#include "tserver.h"
#include "graph_time.h"

/* sgt unite_temps */

bool graph_sgt(t_fds *client, char *cmd __attribute__((unused)))
{
  sendf(client, "sgt %f", get_delay());
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
