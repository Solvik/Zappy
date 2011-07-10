/*
** player.h for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 15:55:26 2011 solvik blum
** Last update Wed Jul  6 17:51:43 2011 solvik blum
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
