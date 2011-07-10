/*
** pfk.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_pfk(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_player	*p;

  (void)pooler;
  if (!(p = get_player_by_id(visu, atoi(cmd->argv[1]))))
    return (0);
  printf("Le joueur #%s pond un oeuf !!\n", cmd->argv[1]);
  return (1);
}
