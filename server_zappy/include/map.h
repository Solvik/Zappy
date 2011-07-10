/*
** map.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		MAP_H_
# define	MAP_H_

#  include	"ztypes.h"
#  include	"list.h"

typedef		struct
{
  t_list 	*stones;
  t_list 	*players;
  t_list 	*eggs;
  uint		food;
}		t_box;

typedef		struct
{
  uint		width;
  uint		height;
  t_box		*map;
}		t_map;

#endif		/* !MAP_H_ */
