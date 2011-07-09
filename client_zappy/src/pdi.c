/*
** pdi.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 17:18:49 2011 solvik blum
** Last update Sat Jul  9 18:49:52 2011 solvik blum
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
