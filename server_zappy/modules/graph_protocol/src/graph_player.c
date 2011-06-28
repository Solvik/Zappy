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


bool handle_ppo(t_fds *client, char *cmd)
{
  (void)client;
  /*
    ppo numero_joueur X Y orientation
   */
}

bool handle_plv(t_fds *client, char *cmd)
{
  (void)client;
  /*
    plv numero_joueur niveau
   */
}

bool handle_pin(t_fds *client, char *cmd)
{
  (void)client;
  /*
    pin numero_joueur X Y quantite_pierre quantite_bouffe
   */
}

bool handle_pnw(t_fds *client, char *cmd)
{
  sends(client, "pnw 0 2 5 1 1 LOL");
}
