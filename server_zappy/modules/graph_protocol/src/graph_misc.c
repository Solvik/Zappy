/*
** graph_misc.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Thu Jun 30 11:30:48 2011 guillaume gelin
** Last update Thu Jun 30 12:07:53 2011 guillaume gelin
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include "tserver.h"
#include "graph_misc.h"

/* Send winner team name */

bool	graph_seg(t_fds *client, char *cmd __attribute__((unused)))
{
  char	*to_send;

  asprintf(&to_send, "seg %s", /* winner_team */ "toto");
  sends(client, to_send);
  free(to_send);
  return (true);
}

/* Send server msg */

bool	graph_smg(t_fds *client, char *cmd __attribute__((unused)))
{
  char	*to_send;

  asprintf(&to_send, "smg %s", /* server msg */ "Top CoOl!");
  sends(client, to_send);
  free(to_send);
  return (true);
}

/* Unknow command */

bool	graph_suc(t_fds *client, char *cmd __attribute__((unused)))
{
  sends(client, "suc");
  return (true);
}

/* Bad command parameter */

bool	graph_sbp(t_fds *client, char *cmd __attribute__((unused)))
{
  sends(client, "sbp");
  return (true);
}
