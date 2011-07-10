/*
** zappy_protocol.h for Zappy in ./server_zappy/modules/zappy_protocol/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		ZAPPY_PROTOCOL_H_
# define	ZAPPY_PROTOCOL_H_

#include	"napi.h"
#include	"module.h"

extern t_module	*zappy_module;
t_module	*get_module(void);

int		zappy_avance(t_fds *, char *);
int		zappy_droite(t_fds *, char *);
int		zappy_gauche(t_fds *, char *);
int		zappy_voir(t_fds *, char *);
int		zappy_inventaire(t_fds *, char *);
int		zappy_prend(t_fds *, char *);
int		zappy_pose(t_fds *, char *);
int		zappy_expulse(t_fds *, char *);
int		zappy_broadcast(t_fds *, char *);
int		zappy_incantation(t_fds *, char *);
int		zappy_connect_nbr(t_fds *, char *);
int		zappy_fork(t_fds *, char *);

e_stone		is_stone(char *);
uint		get_ressource_id(char *);

int		first_quad(int, void *);
int		second_quad(int, void *);
int		third_quad(int, void *);
int		fourth_quad(int, void *);

int		get_sound_direction(int, void *);

bool		handshaking(t_fds *, char *);
bool		disconnection(fds);
double		timer(void);
bool		update(double);

bool		zappy_handshaking(t_fds *, char *);
bool		zappy_disconnection(fds);
double		zappy_timer(void);
bool		zappy_update(double);

#endif		/* !ZAPPY_PROTOCOL_H_ */
