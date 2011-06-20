
#ifndef		SERV_ZAPPY_NET_H_
# define	SERV_ZAPPY_NET_H_

#include	"network.h"

bool	net_wait_clients(void);

bool	net_port_unique(int);
bool	net_bind(uint);

#endif		/* !SERV_ZAPPY_NET_H_ */
