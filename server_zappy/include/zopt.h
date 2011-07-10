/*
** zopt.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		ZAPPY_OPT
# define	ZAPPY_OPT

#include	"list.h"
#include	"ztypes.h"

typedef		struct
{
  uint		seed;
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
