/*
** graph_events.h for Zappy in ./server_zappy/modules/graph_protocol/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		GRAPH_EVENTS_H_
# define	GRAPH_EVENTS_H_

# include <stdbool.h>

/*
** graph_event_over.c
*/

bool	graph_eppo(void *);
bool	graph_ebct(void *);
bool	graph_epin(void *);
bool	graph_eplv(void *);

/*
** graph_event_server.c
*/

bool	graph_pnw(void *);
bool	graph_pdi(void *);
bool	graph_seg(void *);
bool	graph_smg(void *);

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
