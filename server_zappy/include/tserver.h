
#ifndef		TSERV_H_
# define	TSERV_H_

#  include	"module.h"
#  include	"network.h"
#  include	"map.h"
#  include	"zopt.h"

typedef		struct
{
  t_map		map;
  t_zopt	options;
  fds		pool;
  t_list *	module;		// t_module
  t_list *	team;		// t_module
}		t_server;

uint		get_map_width(void);
uint		get_map_height(void);
t_box *		get_map(void);
uint		get_map_max(void);
t_box *		get_box(uint, uint);
t_list *	get_modules(void);

void		set_map_width(uint);
void		set_map_height(uint);
void		set_map(t_box *);
bool		set_new_module(t_module *);

bool		gserv_const(bool created);

#endif		/* !TSERV_H_ */
