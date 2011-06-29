
#ifndef		TSERV_H_
# define	TSERV_H_

#  include	"module.h"
#  include	"network.h"
#  include	"map.h"
#  include	"zopt.h"

typedef		struct
{
  int		port;
}		t_netinfo;

typedef		struct
{
  t_netinfo	net;
  t_map		map;
  fds		pool;
  t_list *	module;		// t_module
  t_list *	team;		// t_team
  bool		run;
}		t_server;

uint		get_map_width(void);
uint		get_map_height(void);
t_box *		get_map(void);
uint		get_map_max(void);
t_box *		get_box(uint, uint);
t_list *	get_modules(void);

int		get_port(void);

fds *		get_pool(void);

void		set_map_width(uint);
void		set_map_height(uint);
void		set_map(t_box *);
bool		set_new_module(t_module *);

void		set_port(int);

bool		gserv_const(bool created);

#endif		/* !TSERV_H_ */
