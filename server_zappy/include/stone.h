/*
** stone.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		STONE_H_
# define	STONE_H_

#include "ztypes.h"

typedef		enum
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NONE
  }		e_stone;

typedef		struct
{
  e_stone	type;
  uint		nb;
}		t_stone;

void		map_random_fill(void);
void		map_random_food(void);
void		map_random_stone(void);

#endif		/* !STONE_H_ */
