/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sun Jul  3 22:32:39 2011 solvik blum
*/

#include <stdlib.h>

#include "player.h"
#include "server_zappy.h"


int		zappy_connect_nbr(t_fds *client, char *cmd)
{
  int		r;
  char		*msg;
  t_team	*team;

  (void)cmd;
  team = get_team_of_player(player);
  r = asprintf(&msg, "%d", team->max_conn);
  sends(client, msg);
  if (msg)
    free(msg);
  return (1);
}
