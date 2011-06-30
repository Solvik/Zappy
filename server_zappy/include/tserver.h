
#ifndef		TSERV_H_
# define	TSERV_H_

#  include	"module.h"
#  include	"network.h"
#  include	"map.h"
#  include	"team.h"
#  include	"player.h"
#  include	"stone.h"

typedef		struct
{
  uint		port;
  uint		delay;
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

t_player *	new_player(void);

uint		get_map_width(void);
uint		get_map_height(void);
t_box *		get_map(void);
uint		get_map_max(void);

t_box *		get_box(uint, uint);
uint		getbox_nbstones(uint, uint, e_stone);

int		get_port(void);
fds *		get_pool(void);

t_list *	get_teams(void);
t_list *	get_players(uint, uint);
t_team *	get_team_of_player(t_player *);

t_list *	get_modules(void);

void		set_map_width(uint);
void		set_map_height(uint);
void		set_map(t_box *);

bool		setbox_addstone(uint, uint, e_stone, uint);
bool		setbox_delstone(uint, uint, e_stone, uint);

bool		set_new_module(t_module *);
void		set_port(int);

bool		add_player(t_player *, char *, uint, uint);

bool		gserv_const(bool);

#endif		/* !TSERV_H_ */
