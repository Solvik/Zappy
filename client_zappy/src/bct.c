/*
** bct.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 16:54:47 2011 solvik blum
** Last update Wed Jul  6 17:54:06 2011 solvik blum
*/

#include	<stdlib.h>

#include	"visu_func.h"
#include	"client_zappy.h"

static bool             match_box(void *data, void *coor)
{
  return ((((t_box *)data)->x == ((int *)coor)[0]) &&
	  (((t_box *)data)->y == ((int *)coor)[1]));
}

int		visu_bct(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  int		coor[2];
  t_box		*box;
  t_box		*tmp_box;

  (void)pooler;
  coor[0] = atoi(cmd->argv[1]);
  coor[1] = atoi(cmd->argv[2]);
  box = malloc(sizeof(*box));
  box->x = coor[0];
  box->y = coor[1];
  box->food = atoi(cmd->argv[3]);
  box->linemate = atoi(cmd->argv[4]);
  box->deraumere = atoi(cmd->argv[5]);
  box->sibur = atoi(cmd->argv[6]);
  box->mendiane = atoi(cmd->argv[7]);
  box->phiras = atoi(cmd->argv[8]);
  box->thystame = atoi(cmd->argv[9]);
  if ((tmp_box = get_data_as_arg(visu->map, match_box, coor)))
    tmp_box = box;
  else if (!put_in_list(&(visu->map), box))
    return (0);
  return (1);
}

int		send_bct(t_fds *pooler, t_cmd *cmd)
{
  (void)cmd;
  sends(pooler, "bct");
  return (1);
}