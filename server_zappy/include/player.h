/*
** player.h for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 15:55:26 2011 solvik blum
** Last update Wed Jun 29 10:56:57 2011 solvik blum
*/

#ifndef PLAYER_H_
# define PLAYER_H_


#  include	"ztypes.h"
#  include	"list.h"
#  include	"network.h"

#define		player_data	((t_player *)(client->data))

typedef enum
  {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
  }		e_direction;

typedef struct	s_player
{
  uint		level;
  uint		life;
  uint		x;
  uint		y;
  t_list	*ressources;	// t_ressource
  e_direction	direction;
}		t_player;

typedef struct	s_resource
{
  char		*name;
  int		n;
}		t_ressource;

#endif /* PLAYER_H_ */
