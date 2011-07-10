/*
** graph_event_incant.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define	_GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "player.h"
#include "graph_events.h"
#include "sends_all.h"

bool	graph_pic(void *data)
{
  t_list *players;
  t_list *pdata;
  t_fds *client;
  char *to_send;
  int i;

  i = 0;
  client = (t_fds *)data;
  if (asprintf(&to_send, "pic %d %d %d",
	       player_data->x, player_data->y,
	       player_data->level + 1) == -1)
    return (false);
  players = get_box_players(player_data->x, player_data->y);
  while ((pdata = get_data_at(players, i)) && ++i)
    if (asprintf(&to_send, "%s %d", to_send, ((t_player *)pdata)->id) == -1)
      return (false);
  printf("%s", to_send);
  sends_all(to_send);
  free(to_send);
  return (true);
}

bool	graph_pie(void *data)
{
  sendf_all("pie %d %d %d",
	    ((t_generic *)data)->ui1,
	    ((t_generic *)data)->ui2,
	    ((t_generic *)data)->ui3);
  return (true);
}

