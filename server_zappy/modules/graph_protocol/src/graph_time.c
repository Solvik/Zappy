/*
** graph_time.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Thu Jun 16 17:05:11 2011 seb
** Last update Sat Jul  9 18:44:03 2011 solvik blum
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
