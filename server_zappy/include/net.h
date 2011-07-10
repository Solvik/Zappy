/*
** net.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		SERV_ZAPPY_NET_H_
# define	SERV_ZAPPY_NET_H_

# include	<stdbool.h>
# include	"network.h"

bool		net_wait_clients(void);

bool		net_port_unique(int);
bool		net_bind(uint*);

bool		net_close(fds);
bool		net_close_msg(fds, char const *, ...);

#endif		/* !SERV_ZAPPY_NET_H_ */
