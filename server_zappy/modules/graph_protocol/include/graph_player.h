/*
** graph_player.h for Zappy in ./server_zappy/modules/graph_protocol/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		GRAPH_PLAYER_H_
# define	GRAPH_PLAYER_H_

# include <stdbool.h>
# include "network.h"

bool graph_ppo(t_fds *, char *);
bool graph_plv(t_fds *, char *);
bool graph_pin(t_fds *, char *);

#endif		/* GRAPH_PLAYER_H_ */
