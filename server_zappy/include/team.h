/*
** team.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:07:38 2011 Julien Di Marco
** Last update Sun Jul  3 22:26:12 2011 solvik blum
*/

#ifndef		ZAPPY_TEAM_H_
# define	ZAPPY_TEAM_H_

#  include	"list.h"

typedef		struct
{
  char		*name;
  uint		max_conn;
  t_list 	*players;
  t_list	*egg_list;
}		t_team;

#endif		/* !ZAPPY_TEAM_H_ */
