/*
** graph_event_misc.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Thu Jun 30 11:30:48 2011 guillaume gelin
** Last update Wed Jul  6 16:44:47 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"

/* seg: Send winner team name */

bool	graph_seg(void *data)
{
  char	*to_send;

  asprintf(&to_send, "seg %s", (char*)data);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* smg: Send server msg */

bool	graph_smg(void *data)
{
  char	*to_send;

  asprintf(&to_send, "smg %s", (char*)data);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* suc: Unknow command */

bool	graph_suc(void *data)
{
  sends((t_fds *)data, "suc");
  return (true);
}

/* sbp: Bad command parameter */

bool	graph_sbp(void *data)
{
  sends((t_fds *)data, "sbp");
  return (true);
}
