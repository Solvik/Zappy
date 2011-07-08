/*
** net.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:07:59 2011 Julien Di Marco
** Last update Thu Jun 30 05:07:59 2011 Julien Di Marco
*/

#ifndef		SERV_ZAPPY_NET_H_
# define	SERV_ZAPPY_NET_H_

# include	<stdbool.h>
# include	"network.h"

bool	net_wait_clients(void);

bool	net_port_unique(int);
bool	net_bind(uint*);

bool	net_close(fds);
bool	net_close_msg(fds, char const *, ...);

#endif		/* !SERV_ZAPPY_NET_H_ */
