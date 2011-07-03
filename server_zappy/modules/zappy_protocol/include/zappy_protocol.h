/*
** zappy_protocol.h for  in /home/solvik/tek2/proj/Zappy/server_zappy/modules/zappy_protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jun 29 10:24:19 2011 solvik blum
** Last update Sun Jul  3 16:24:34 2011 solvik blum
*/

#ifndef		ZAPPY_PROTOCOL_H_
# define	ZAPPY_PROTOCOL_H_

#include	"napi.h"
#include	"module.h"

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


#endif		/* !ZAPPY_PROTOCOL_H_ */
