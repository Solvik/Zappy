/*
** pdi.c for Zappy in ./client_zappy/src
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

static bool		match_player(void *data, void *arg)
{
  return (data == arg);
}

int		visu_pdi(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_player	*p;

  (void)pooler;
  if (!(p = get_player_by_id(visu, atoi(cmd->argv[1]))))
    return (0);
  del_node_as_arg(&visu->player, match_player, p);
  visu->refresh = true;
  return (1);
}
