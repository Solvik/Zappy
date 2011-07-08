/*
** msz.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 01:09:28 2011 solvik blum
** Last update Wed Jul  6 17:59:09 2011 solvik blum
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_msz(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  (void)pooler;
  visu->width = atoi(cmd->argv[1]);
  visu->height = atoi(cmd->argv[2]);
  if (visu->width <= 0 || visu->height <= 0)
    {
      fprintf(stderr, "Bad Map Size\n");
      exit(EXIT_FAILURE);
    }
  visu->refresh = true;
  return (1);
}


int		send_msz(t_fds *pooler, t_cmd *cmd)
{
  (void)cmd;
  sends(pooler, "msz");
  return (1);
}
