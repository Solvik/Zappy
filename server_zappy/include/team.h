/*
** team.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		ZAPPY_TEAM_H_
# define	ZAPPY_TEAM_H_

#  include	"ztypes.h"
#  include	"list.h"

typedef		struct
{
  char		*name;
  uint		max_conn;
  t_list 	*players;
  t_list	*egg_list;
}		t_team;

#endif		/* !ZAPPY_TEAM_H_ */
