/*
** graph_time.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include <stdbool.h>
#include <string.h>
#include "tserver.h"
#include "graph_time.h"

/* sgt unite_temps */
bool	graph_sgt(t_fds *client, char *cmd __attribute__((unused)))
{
  sendf(client, "sgt %d", (int)get_delay());
  return (true);
}

/* sgt unite_temps */
bool	graph_sst(t_fds *client, char *cmd)
{
  char	*delay;

  strtok(cmd, " ");
  delay = strtok(NULL, " ");
  if (!delay)
    {
      sends(client, "sbp");
      return (false);
    }
  set_delay(atoi(delay));
  graph_sgt(client, cmd);
  return (true);
}
