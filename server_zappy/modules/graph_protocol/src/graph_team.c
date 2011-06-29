/*
** graph_team.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 19:01:45 2011 seb
** Last update Mon Jun 13 19:01:45 2011 seb
*/

#include "network.h"
#include "graph_team.h"

bool handle_tna(t_fds *player, char *cmd)
{
  sends(player, "tna LOL");
  /*
    On envoie tna tean_name\n pour chaque team presente sur la map
   */
}
