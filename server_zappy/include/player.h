/*
** player.h for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 15:55:26 2011 solvik blum
** Last update Mon Jun 13 16:54:55 2011 solvik blum
*/

#ifndef PLAYER_H_
# define PLAYER_H_


#include	"list.h"

enum e_direction
  {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
  }

typedef struct	s_player
{
  int		level;
  int		life;
  int		x;
  int		y;
  t_list	*ressources;
  e_direction	direction
}		t_player;


#endif /* PLAYER_H_ */
