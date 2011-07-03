/*
** graph_player.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 14 16:08:10 2011 seb
** Last update Tue Jun 14 16:08:10 2011 seb
*/


#include <stdlib.h>
#include <string.h>
#include "graph_player.h"

/*
** ppo numero_joueur X Y orientation
*/

bool graph_ppo(t_fds *client, char *cmd)
{
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
  if (!id || (level = get_player_level_by_id(atoi(id))) == -1)
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
