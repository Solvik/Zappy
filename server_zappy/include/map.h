/*
** map.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:08:09 2011 Julien Di Marco
** Last update Thu Jun 30 05:08:09 2011 Julien Di Marco
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
