/*
** plv.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 17:42:18 2011 solvik blum
** Last update Wed Jul  6 18:01:31 2011 solvik blum
*/

#include	<stdlib.h>

#include	"visu_func.h"
#include	"client_zappy.h"
#include	"player.h"

int		visu_plv(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_player	*p;

  (void)pooler;
  if (!(p = get_player_by_id(visu, atoi(cmd->argv[1]))))
    return (0);
  p->level = atoi(cmd->argv[2]);
  return (1);
}

int		send_plv(t_fds *pooler, t_cmd *cmd)
{
  int		r;
  char		*a;

  r = asprintf(&a, "plv %s", cmd->argv[0]);
  sends(pooler, a);
  free(a);
  return (0);
}
