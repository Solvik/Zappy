/*
** exec.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		EXEC_H_
# define	EXEC_H_

# include	<stdbool.h>
# include	"time_.h"
# include	"network.h"

bool		exec_pool(fds, double);
bool		exec_client(fds, double);

bool		exec_event(double);

bool		exec_updates(double);
bool		exec_timer(time__ **, double);

#endif		/* !EXEC_H_ */
