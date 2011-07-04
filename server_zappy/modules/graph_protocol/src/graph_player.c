/*
** graph_player.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 14 16:08:10 2011 seb
** Last update Mon Jul  4 19:48:54 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_player.h"
#include "tserver.h"

/*
** ppo numero_joueur X Y orientation
*/

bool graph_ppo(t_fds *client, char *cmd)
{
  char *id;
  char *to_send;
  unsigned int	x;
  unsigned int	y;
  unsigned int	o;

  to_send = NULL;
  (void)strtok(cmd, " ");
  id = strtok(NULL, " ");
  if (!id || get_player_pos(atoi(id), &x, &y, &o) == false)
    {
      sends(client, "sbp");
      return (true);
    }
  asprintf(&to_send, "ppo %s %d %d %d", id, x, y, o);
  sends(client, to_send);
  free(to_send);
  return (true);
}

/*
** plv numero_joueur niveau
*/

bool graph_plv(t_fds *client, char *cmd)
{
  char *id;
  char *to_send;
  int	level;

  to_send = NULL;
  (void)strtok(cmd, " ");
  id = strtok(NULL, " ");
  printf("%s\n", id);
  if (!id || (level = get_player_level(atoi(id))) == 0)
    {
      sends(client, "sbp");
      return (true);
    }
  asprintf(&to_send, "plv %s %d", id, level);
  sends(client, to_send);
  free(to_send);
  return (true);
}

/*
**  pin numero_joueur X Y quantite_pierre quantite_bouffe
*/

bool graph_pin(t_fds *client, char *cmd)
{

  return (true);
}

bool graph_pnw(t_fds *client, char *cmd)
{
  sends(client, "pnw 0 2 5 1 1 LOL");
  return (true);
}
