/*
** visu_func.h for Zappy in ./client_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		VISU_FUNC_H_
# define	VISU_FUNC_H_

#include	"client_zappy.h"

typedef struct	s_ptr
{
  char		*cmd;
  int          (*f)();
  int		argc;
}               t_ptr;

int		visu_bienvenue(t_fds *, t_cmd *, t_visu *);
int		visu_msz(t_fds *, t_cmd *, t_visu *);
int		visu_smg(t_fds *, t_cmd *, t_visu *);
int		visu_suc(t_fds *, t_cmd *, t_visu *);
int		visu_sbp(t_fds *, t_cmd *, t_visu *);
int		visu_tna(t_fds *, t_cmd *, t_visu *);
int		visu_pnw(t_fds *, t_cmd *, t_visu *);
int		visu_ppo(t_fds *, t_cmd *, t_visu *);
int		visu_plv(t_fds *, t_cmd *, t_visu *);
int		visu_pin(t_fds *, t_cmd *, t_visu *);
int		visu_bct(t_fds *, t_cmd *, t_visu *);
int		visu_pdi(t_fds *, t_cmd *, t_visu *);
int		visu_pfk(t_fds *, t_cmd *, t_visu *);
int		visu_enw(t_fds *, t_cmd *, t_visu *);
int		play_sound(t_fds *, t_cmd *, t_visu *);

#endif		/* !VISU_FUNC_H_ */
