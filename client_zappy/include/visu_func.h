/*
** visu_func.h for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 00:58:14 2011 solvik blum
** Last update Wed Jul  6 01:11:01 2011 solvik blum
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

#endif		/* !VISU_FUNC_H_ */
