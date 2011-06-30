/*
** team.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:07:38 2011 Julien Di Marco
** Last update Thu Jun 30 05:07:38 2011 Julien Di Marco
*/

#ifndef		ZAPPY_TEAM_H_
# define	ZAPPY_TEAM_H_

#  include	"list.h"

typedef		struct
{
  char		*name;
  t_list 	*players;
}		t_team;

#endif		/* !ZAPPY_TEAM_H_ */
