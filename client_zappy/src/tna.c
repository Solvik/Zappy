/*
** tna.c for Zappy in ./client_zappy/src
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

static bool             match_team(void *data, void *arg)
{
  int			n;

  n = !strcmp(((t_team *)data)->name, (char *)arg);
  return ((!n) ? true : false);
}

int		visu_tna(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_team	*t;
  t_team	*tmp;

  (void)pooler;
  if (!(t = malloc(sizeof(*t))))
    return (0);
  t->name = strdup(cmd->argv[1]);
  if (!(tmp = get_data_as_arg(visu->teams, match_team, cmd->argv[1])) &&
      (!put_in_list(&(visu->teams), t)))
    {
      free(t);
      return (0);
    }
  return (1);
}

int		send_tna(t_fds *pooler, t_cmd *cmd)
{
  (void)cmd;
  sends(pooler, "tna");
  return (1);
}
