/*
** init.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		ZAPPY_INIT_H_
# define	ZAPPY_INIT_H_

#  include	<stdbool.h>
#  include	"zopt.h"
#  include	"map.h"

bool		init(int, char **);
bool		init_opt(int, char **, t_zopt *);
bool		init_random(t_zopt *);
bool		init_network(t_zopt *);
bool		init_map(t_zopt *);
bool		init_team(t_zopt *);
bool		init_modules(t_zopt *);

#endif		/* !ZAPPY_INIT_H_ */

