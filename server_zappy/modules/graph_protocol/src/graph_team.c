/*
** graph_team.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include <unistd.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_team.h"

bool graph_tna(t_fds *client, char *cmd __attribute__((unused)))
{
  unsigned int	i;
  t_list	*teams;
  void		*data;

  i = 0;
  teams = get_teams();
  while ((data = get_data_at(teams, i)) && ++i)
    sendf(client, "tna %s", ((t_team *)data)->name);
  return (true);
}
