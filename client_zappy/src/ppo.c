/*
** ppo.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"visu_func.h"
#include	"client_zappy.h"
#include	"player.h"

int		visu_ppo(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_player	*p;

  (void)pooler;
  if (!(p = get_player_by_id(visu, atoi(cmd->argv[1]))))
    return (0);
  p->x = atoi(cmd->argv[2]);
  p->y = atoi(cmd->argv[3]);
  p->direction = atoi(cmd->argv[4]) - 1;
  visu->refresh = true;
  return (1);
}

int		send_ppo(t_fds *pooler, t_cmd *cmd)
{
  int		r;
  char		*a;

  r = asprintf(&a, "ppo %s", cmd->argv[0]);
  sends(pooler, a);
  free(a);
  return (0);
}
