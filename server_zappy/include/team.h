
#ifndef		ZAPPY_TEAM_H_
# define	ZAPPY_TEAM_H_

#  include	"list.h"

typedef		struct
{
  char *	name;
  t_list *	players;		// t_player *
}		t_team;

#endif		/* !ZAPPY_TEAM_H_ */
