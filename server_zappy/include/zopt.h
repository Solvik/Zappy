
#ifndef		ZAPPY_OPT
# define	ZAPPY_OPT

#include	"list.h"
#include	"ztypes.h"

typedef		struct
{
  uint		port;
  uint		width;
  uint		height;
  uint		nb_client;
  uint		delay;
  uint		time;
  t_list *	team;		// char *
  t_list *	module;		// char *
}		t_zopt;

#endif		/* !ZAPPY_OPT */
