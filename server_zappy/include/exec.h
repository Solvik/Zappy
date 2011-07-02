/*
** exec.h for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Jun 28 21:41:37 2011 julien di-marco
** Last update Tue Jun 28 21:41:37 2011 julien di-marco
*/

#ifndef		EXEC_H_
# define	EXEC_H_

# include	"time_.h"
# include	"network.h"

bool		exec_pool(fds, double);
bool		exec_client(fds, double);

bool		exec_updates(double);
bool		exec_timer(time__ **, double);

#endif		/* !EXEC_H_ */
