/*
** get_player_by_id.c for Zappy in ./client_zappy/src
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
#include	"player.h"

static bool	match_player(void *data, void *arg)
{
  return (((t_player *)data)->id == *(uint *)arg);
}

t_player	*get_player_by_id(t_visu *visu, int id)
{
  return (get_data_as_arg(visu->player, match_player, &id));
}
