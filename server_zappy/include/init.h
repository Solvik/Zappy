
#ifndef		ZAPPY_INIT_H_
# define	ZAPPY_INIT_H_

#  include	<stdbool.h>
#  include	"zopt.h"
#  include	"map.h"

bool		init(int, char **);
bool		init_opt(int, char **, t_zopt *);
bool		init_network(t_zopt *);
bool		init_map(t_zopt *);

#endif		/* !ZAPPY_INIT_H_ */

