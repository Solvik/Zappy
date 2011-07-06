/*
** get_player_id.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 17:47:29 2011 solvik blum
** Last update Wed Jul  6 18:00:50 2011 solvik blum
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
