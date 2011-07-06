/*
** graph_event_cmd.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Thu Jun 30 11:30:48 2011 guillaume gelin
** Last update Wed Jul  6 19:37:56 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"

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
