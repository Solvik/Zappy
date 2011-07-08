/*
** graph_team.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 19:01:45 2011 seb
** Last update Fri Jul  8 06:22:41 2011 ramnes
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
