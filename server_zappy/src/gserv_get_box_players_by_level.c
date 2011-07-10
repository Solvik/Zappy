/*
** gserv_get_box_players_by_level.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>

#include	"map.h"
#include	"player.h"
#include	"tserver.h"
#include	"server_zappy.h"

static bool	match_player_different_level(void * player, void * level)
{
  return (((t_player *)player)->level != *(uint*)level);
}

t_list		*get_box_players_by_level(uint x, uint y, uint level)
{
  t_box		*box;

  if (!(box = get_box(x, y)) ||
      get_data_as_arg(box->players, match_player_different_level, &level))
    return (NULL);
  return (box->players);
}
