/*
** zopt.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:07:34 2011 Julien Di Marco
** Last update Thu Jun 30 05:07:34 2011 Julien Di Marco
*/

#ifndef		ZAPPY_OPT
# define	ZAPPY_OPT

#include	"list.h"
#include	"ztypes.h"

typedef		struct
{
  uint		port;
  uint		width;
  uint		height;
  uint		nb_clients;
  double	delay;
  double	time;
  t_list	*team;
  t_list 	*module;
}		t_zopt;

#endif		/* !ZAPPY_OPT */
