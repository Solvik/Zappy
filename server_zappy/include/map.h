
#ifndef		MAP_H_
# define	MAP_H_

#  include	"ztypes.h"
#  include	"List/include/list.h"

typedef		struct
{
  uint		width;
  uint		height;
  t_list *	map;
}		t_map;

#endif		/* !MAP_H_ */
