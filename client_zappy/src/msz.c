/*
** msz.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
