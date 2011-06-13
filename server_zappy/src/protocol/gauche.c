/*
** gauche.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 17:32:06 2011 solvik blum
** Last update Mon Jun 13 17:39:17 2011 solvik blum
*/

#include "player.h"
#include "server_zappy.h"

int		zappy_gauche(t_player *player)
{
  player->direction = (player->direction + 3) % 4;
  /* Envoyer OK\n */
  return (0);
}
