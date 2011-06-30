/*
** graph_player.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 14 16:08:10 2011 seb
** Last update Tue Jun 14 16:08:10 2011 seb
*/

#include "graph_player.h"

/*
** ppo numero_joueur X Y orientation
*/

bool graph_ppo(t_fds *__, char *_)
{
  (void)__;
  (void)_;
  return (true);
}

/*
** plv numero_joueur niveau
*/

bool graph_plv(t_fds *__, char *_)
{
  (void)__;
  (void)__;
  (void)_;
  return (true);
}

/*
**  pin numero_joueur X Y quantite_pierre quantite_bouffe
*/

bool graph_pin(t_fds *__, char *_)
{
  (void)__;
  (void)_;
  return (true);
}

bool graph_pnw(t_fds *client, char *_)
{
  (void)_;
  sends(client, "pnw 0 2 5 1 1 LOL");
  return (true);
}
