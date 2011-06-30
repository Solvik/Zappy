/*
** init.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:08:12 2011 Julien Di Marco
** Last update Thu Jun 30 05:08:12 2011 Julien Di Marco
*/

#ifndef		ZAPPY_INIT_H_
# define	ZAPPY_INIT_H_

#  include	<stdbool.h>
#  include	"zopt.h"
#  include	"map.h"

bool		init(int, char **);
bool		init_opt(int, char **, t_zopt *);
bool		init_network(t_zopt *);
bool		init_map(t_zopt *);
bool		init_modules(t_zopt *);

#endif		/* !ZAPPY_INIT_H_ */

