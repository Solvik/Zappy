/*
** graph_event_cmd.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"

/* suc: UnknowCmd */
bool	graph_suc(void *data)
{
  sends((t_fds *)data, "suc");
  return (true);
}

/* sbp: BadParams */
bool	graph_sbp(void *data)
{
  sends((t_fds *)data, "sbp");
  return (true);
}
