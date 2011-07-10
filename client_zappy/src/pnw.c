/*
** pnw.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 17:28:22 2011 solvik blum
** Last update Sun Jul 10 15:57:31 2011 solvik blum
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
