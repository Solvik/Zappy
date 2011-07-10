/*
** player.h for Zappy in ./client_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef PLAYER_H_
# define PLAYER_H_

#  include	"ztypes.h"
#  include	"list.h"
#  include	"network.h"

typedef enum
  {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
  }		e_direction;

typedef struct	s_team
{
  char		*name;
}		t_team;

typedef struct	s_player
{
  uint		id;
  uint		level;
  uint		life;
  uint		x;
  uint		y;
  t_list 	*stones;
  e_direction	direction;
  //  t_team	*team;
  char		*team;
}		t_player;

#endif /* PLAYER_H_ */
