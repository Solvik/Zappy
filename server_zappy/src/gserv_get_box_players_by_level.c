/*
** gserv_get_players_by_level.c for  in /home/solvik/tek2/proj/Zappy/server_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 23:10:32 2011 solvik blum
** Last update Sun Jul  3 23:20:11 2011 solvik blum
*/

#include	<stdlib.h>

#include	"map.h"
#include	"player.h"
#include	"tserver.h"
#include	"server_zappy.h"

static bool	match_player(void * player, void* level)
{
  if (((t_player *)player)->level != *(uint*)level)
    return (false);
  return (true);
}

t_list		*get_box_players_by_level(uint x, uint y, uint level)
{
  t_list	*players;
  t_box		*box;

  if (!(box = get_box(x, y)))
    return (false);
  players = sub_list_arg(box->players, match_player, &level);
  return (players);
}
