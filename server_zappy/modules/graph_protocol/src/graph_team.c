/*
** graph_team.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 19:01:45 2011 seb
** Last update Wed Jun 29 15:08:52 2011 guillaume gelin
*/

#include "list.h"
#include "team.h"
#include "network.h"
#include "graph_team.h"

bool graph_tna(t_fds *player, char *cmd)
{
  unsigned int	i;
  t_list	*teams;
  char		*to_send;
  void		*data;

  i = 0;
  teams = get_teams();
  while ((data = get_data_at(teams, i)) && ++i)
    {
      asprintf(&to_send, "tna %s", ((t_team *)data)->name);
      sends(player, to_send);
      free(to_send);
    }
}
