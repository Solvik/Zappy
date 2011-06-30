/*
** stone.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:07:40 2011 Julien Di Marco
** Last update Thu Jun 30 05:07:40 2011 Julien Di Marco
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

#endif		/* !STONE_H_ */
