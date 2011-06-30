/*
** new_player.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:04:23 2011 Julien Di Marco
** Last update Thu Jun 30 05:04:23 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	<strings.h>
#include	"conf.h"
#include	"player.h"

t_player *	new_player(void)
{
  static uint	id = 0;
  t_player *	player;

  if (!(player = malloc(sizeof(*player))))
    return (NULL);
  bzero(player, sizeof(*player));
  player->id = id;
  player->level = 1;
  player->life = default_life;
  player->x = 0;
  player->y = 0;
  player->stones = NULL;
  player->direction = EAST;
  ++id;
  return (player);
}
