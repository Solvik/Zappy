/*
** pin.c for Zappy in ./client_zappy/src
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
#include	"player.h"

int		visu_pin(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_player	*p;
  t_box		*box;

  (void)pooler;
  if (!(p = get_player_by_id(visu, atoi(cmd->argv[1]))))
    return (0);
  p->x = atoi(cmd->argv[2]);
  p->y = atoi(cmd->argv[3]);
  if (!(box = malloc(sizeof(*box))))
    return (0);
  box->food = atoi(cmd->argv[4]);
  box->linemate = atoi(cmd->argv[5]);
  box->deraumere = atoi(cmd->argv[6]);
  box->sibur = atoi(cmd->argv[7]);
  box->mendiane = atoi(cmd->argv[8]);
  box->phiras = atoi(cmd->argv[9]);
  box->thystame = atoi(cmd->argv[10]);
  if (!put_in_list(&(p->stones), box))
    return (0);
  return (1);
}

int		send_pin(t_fds *pooler, t_cmd *cmd)
{
  int		r;
  char		*a;

  r = asprintf(&a, "pin %s", cmd->argv[0]);
  sends(pooler, a);
  free(a);
  return (0);
}
