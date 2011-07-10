/*
** bct.c for Zappy in ./client_zappy/src
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

static void	fill_data(t_box *box, t_cmd *cmd)
{
  box->food = atoi(cmd->argv[3]);
  box->linemate = atoi(cmd->argv[4]);
  box->deraumere = atoi(cmd->argv[5]);
  box->sibur = atoi(cmd->argv[6]);
  box->mendiane = atoi(cmd->argv[7]);
  box->phiras = atoi(cmd->argv[8]);
  box->thystame = atoi(cmd->argv[9]);
}

int		visu_bct(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  int		coor[2];
  t_box		*box;
  t_box		*tmp_box;

  (void)pooler;
  coor[0] = atoi(cmd->argv[1]);
  coor[1] = atoi(cmd->argv[2]);
  if (!(box = malloc(sizeof(*box))))
    return (0);
  box->x = coor[0];
  box->y = coor[1];
  fill_data(box, cmd);
  if ((tmp_box = get_data_as_arg(visu->map, match_box, coor)))
    tmp_box = box;
  else if (!put_in_list(&(visu->map), box))
    return (0);
  draw_stones(visu, box->x, box->y);
  if (visu->info)
    SDL_FillRect(visu->info, NULL, SDL_MapRGB(visu->screen->format,
					      253, 63, 146));
  draw_info(visu);
  get_info((box->x) / 64,
	   (box->y) / 64, visu);
  return (1);
}

int		send_bct(t_fds *pooler, t_cmd *cmd)
{
  char		*ret;

  asprintf(&ret, "bct %s %s", cmd->argv[1], cmd->argv[2]);
  sends(pooler, ret);
  if (ret)
    free(ret);
  return (1);
}
