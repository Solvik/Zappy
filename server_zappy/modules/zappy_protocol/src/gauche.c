/*
** gauche.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 17:32:06 2011 solvik blum
** Last update Wed Jul  6 19:23:50 2011 ramnes
*/

#include "player.h"
#include "server_zappy.h"
#include "network.h"

int		zappy_gauche(t_fds *client, char *cmd)
{
  (void)cmd;
  player_data->direction = (player_data->direction + 3) % 4;
  sends(client, "ok");
  return (0);
}
