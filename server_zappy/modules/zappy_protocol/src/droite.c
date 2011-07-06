/*
** droite.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 16:50:23 2011 solvik blum
** Last update Wed Jul  6 19:23:16 2011 ramnes
*/

#include <stdlib.h>

#include "network.h"
#include "player.h"
#include "server_zappy.h"

int		zappy_droite(t_fds *client, char *cmd)
{
  (void)cmd;
  player_data->direction = (player_data->direction + 1) % 4;
  sends(client, "ok");
  return (0);
}
