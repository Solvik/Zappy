
#include		<stdlib.h>
#include		"tserver.h"

uint			get_player_level(uint id)
{
  t_player *	player;

  if (!(player = get_player_by_id(id)))
    return (0);
  return (player->level);
}

bool			get_player_pos(uint id, uint * x, uint * y)
{
  t_player *	player;

  if (!(player = get_player_by_id(id)))
    return (false);
  *x = player->x;
  *y = player->y;
  return (true);
}

t_list * /* t_stone */	get_player_stones(uint id)
{
  t_player *		player;

  if (!(player = get_player_by_id(id)))
    return (NULL);
  return (player->stones);
}

uint			get_player_food(uint id)
{
  t_player *		player;

  if (!(player = get_player_by_id(id)))
    return (0);
  return (player->life);
}

