/*
** graph_team.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 19:01:45 2011 seb
** Last update Wed Jul  6 20:23:10 2011 ramnes
*/

#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tserver.h"
#include "graph_team.h"

bool graph_tna(t_fds *client, char *cmd __attribute__((unused)))
{
  unsigned int	i;
  t_list	*teams;
  char		*to_send;
  void		*data;

  i = 0;
  teams = get_teams();
  while ((data = get_data_at(teams, i)) && ++i)
    {
      if (asprintf(&to_send, "tna %s", ((t_team *)data)->name) == -1)
	return (false);
      sends(client, to_send);
      free(to_send);
    }
  return (true);
}
