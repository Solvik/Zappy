/*
** graph_events.h for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Thu Jun 30 11:32:47 2011 guillaume gelin
** Last update Wed Jul  6 17:04:43 2011 ramnes
*/

#ifndef		GRAPH_EVENTS_H_
# define	GRAPH_EVENTS_H_

# include <stdbool.h>

/* graph_event_global.c */

bool	graph_pnw(void *);
bool	graph_pex(void *);
bool	graph_pbc(void *);

/* graph_event_player.c */

bool	graph_pfk(void *);
bool	graph_pdr(void *);
bool	graph_pgt(void *);
bool	graph_pdi(void *);

/* graph_event_misc.c */

bool	graph_seg(void *);
bool	graph_smg(void *);
bool	graph_suc(void *);
bool	graph_sbp(void *);

#endif		/* GRAPH_EVENTS_H_ */
