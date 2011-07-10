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

static bool	match_team(void *data, void *arg)
{
  int		n;

  n = !strcmp(((t_team *)data)->name, (char *)arg);
  return ((!n) ? true : false);
}

int		visu_pnw(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_team	*t;
  t_player	*p;

  (void)pooler;
  p = malloc(sizeof(*p));
  p->id = atoi(cmd->argv[1]);
  p->x = atoi(cmd->argv[2]);
  p->y = atoi(cmd->argv[3]);
  if ((t = get_data_as_arg(visu->teams, match_team, cmd->argv[6])))
    p->team = t;
  p->direction = atoi(cmd->argv[4]) - 1;
  p->level = atoi(cmd->argv[5]);
  if (!put_in_list(&(visu->player), p))
    return (0);
  visu->refresh = true;
  return (1);
}
