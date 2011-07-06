/*
** bienvenue.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 00:56:54 2011 solvik blum
** Last update Wed Jul  6 01:12:03 2011 solvik blum
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_bienvenue(t_fds *pooler, t_visu *visu, t_cmd *cmd)
{
  (void)cmd;
  (void)visu;
  sends(pooler, "GRAPHIC");
  return (1);
}
