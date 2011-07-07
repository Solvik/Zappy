/*
** droite.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 16:50:23 2011 solvik blum
** Last update Thu Jul  7 20:54:42 2011 ramnes
*/

#include "player.h"
#include "server_zappy.h"
#include "network.h"
#include "napi.h"

int		zappy_droite(t_fds *client, char *cmd)
{
  (void)cmd;
  player_data->direction = (player_data->direction + 1) % 4;
  sends(client, "ok");
  event_relative_dispatch("PlayerMove", client, 0);
  return (0);
}
