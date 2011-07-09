/*
** graph_events.h for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
**
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
**
** Started on  Thu Jun 30 11:32:47 2011 guillaume gelin
** Last update Fri Jul  8 02:28:29 2011 ramnes
*/

#ifndef		GRAPH_EVENTS_H_
# define	GRAPH_EVENTS_H_

# include <stdbool.h>
# include "tserver.h"

/*
** graph_event_server.c
*/

bool	graph_pnw(void *);
bool	graph_pdi(void *);
bool	graph_seg(void *);
bool	graph_smg(void *);
bool	graph_eppo(void *);

/*
** graph_event_player.c
*/

bool	graph_pex(void *);
bool	graph_pbc(void *);
bool	graph_pfk(void *);
bool	graph_pdr(void *);
bool	graph_pgt(void *);

/*
** graph_event_incant.c
*/

bool	graph_pic(void *);
bool	graph_pie(void *);

/*
** graph_event_egg.c
*/

bool	graph_enw(void *);
bool	graph_eht(void *);
bool	graph_ebo(void *);
bool	graph_edi(void *);

/*
** graph_event_cmd.c
*/

bool	graph_suc(void *);
bool	graph_sbp(void *);

#endif		/* GRAPH_EVENTS_H_ */
