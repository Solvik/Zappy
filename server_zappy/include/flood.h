/*
** flood.h for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Jun 28 20:14:01 2011 julien di-marco
** Last update Tue Jun 28 20:14:01 2011 julien di-marco
*/

#ifndef		FLOOD_H_
# define	FLOOD_H_

# include	"network.h"

typedef struct	_antiflood
{
  char		**array;
  long		read;
  long		write;
  int		size;
}		t_antiflood;

char		*flood_check(fds, char *);
bool		flood_read(fds);

#endif		/* !FLOOD_H_ */
