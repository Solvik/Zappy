/*
** msz.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 01:09:28 2011 solvik blum
** Last update Wed Jul  6 01:10:38 2011 solvik blum
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

/* */
/* Taille de la carte */
/* */

int		visu_msz(t_fds *pooler, t_visu *visu, t_cmd *cmd)
{
  visu->width = atoi(cmd->argv[1]);
  visu->height = atoi(cmd->argv[2]);
  sends(pooler, "msz");
  return (1);
}
