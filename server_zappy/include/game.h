
#ifndef		TSERV_H_
# define	TSERV_H_

#  include	"network.h"
#  include	"map.h"

typedef		struct
{
  t_map		map;
  t_list *	module;		// t_module
}		t_game;

uint		get_map_width(void);
uint		get_map_height(void);

void		set_map_width(uint);
void		set_map_height(uint);
void		set_map(t_box *);

#endif		/* !TSERV_H_ */
