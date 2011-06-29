/*
** gauche.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 17:32:06 2011 solvik blum
** Last update Wed Jun 29 16:31:16 2011 solvik blum
*/

#include "player.h"
#include "server_zappy.h"

int		zappy_gauche(t_fds *client, char *cmd)
{
  (void)cmd;
  player_data->direction = (player_data->direction + 3) % 4;
  sends(client, "ok");
  return (0);
}
