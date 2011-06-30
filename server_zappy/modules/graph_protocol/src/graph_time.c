/*
** graph_time.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Thu Jun 16 17:05:11 2011 seb
** Last update Thu Jun 30 12:09:09 2011 guillaume gelin
*/

#define _GNU_SOURCE

#include <stdio.h>

#include <stdbool.h>
#include <string.h>
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

bool graph_sst(t_fds *client, char *cmd)
{
  char *delay;

  (void)strtok(cmd, " ");
  delay = strtok(NULL, " ");
  if (!delay)
	return (false);
  set_delay(atof(delay));
  graph_sgt(client, cmd);
  return (true);
}
