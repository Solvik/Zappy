
#ifndef		ZAPPY_OPT
# define	ZAPPY_OPT

#include	"ztypes.h"

typedef		struct
{
  uint		port;
  uint		width;
  uint		height;
  uint		nb_client;
  uint		delay;
  uint		time;
}		t_zopt;

/*
** time should be a great option to change the time referential
** wich by default is 1 second aka 1 000 000 usec.
**
*/

#endif		/* !ZAPPY_OPT */
