/*
** pfk.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul 10 16:10:16 2011 solvik blum
** Last update Sun Jul 10 16:42:44 2011 solvik blum
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_pfk(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_player	*p;

  (void)pooler;
  if (!(p = get_player_by_id(visu, atoi(cmd->argv[1]))))
    return (0);
  printf("Le joueur #%s pond un oeuf !!\n", cmd->argv[1]);
  return (1);
}
