
#ifndef		MAP_H_
# define	MAP_H_

#  include	"ztypes.h"
#  include	"list.h"

typedef		struct
{
  t_list *	stones;		// t_stone
  t_list *	players;	// t_players
  t_list *	eggs;		// t_eggs
  uint		food;
}		t_box;

typedef		struct
{
  uint		width;
  uint		height;
  t_box	*	map;
}		t_map;

#endif		/* !MAP_H_ */
