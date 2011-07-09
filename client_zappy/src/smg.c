/*
** smg.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sat Jul  9 18:50:11 2011 solvik blum
** Last update Sat Jul  9 18:50:11 2011 solvik blum
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_smg(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  (void)pooler;
  (void)visu;
  printf("Message from the server: %s\n", cmd->argv[1]);
  return (1);
}
