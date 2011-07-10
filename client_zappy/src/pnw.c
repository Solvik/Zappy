/*
** pnw.c for Zappy in ./client_zappy/src
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

int		visu_pnw(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_player	*p;

  (void)pooler;
  if (!(p = malloc(sizeof(*p))))
    return (0);
  p->id = atoi(cmd->argv[1]);
  p->x = atoi(cmd->argv[2]);
  p->y = atoi(cmd->argv[3]);
  p->stones = NULL;
  p->team = strdup(cmd->argv[6]);
  p->direction = atoi(cmd->argv[4]) - 1;
  p->level = atoi(cmd->argv[5]);
  if (!put_in_list(&(visu->player), p))
    return (0);
  visu->refresh = true;
  return (1);
}
