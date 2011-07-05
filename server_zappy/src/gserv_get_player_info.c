
#include		<stdlib.h>
#include		"tserver.h"

uint			get_player_level(uint id)
{
  t_player *	player;

  if ((player = get_player_by_id(id)) == NULL)
    return (0);
  return (player->level);
}

bool			get_player_pos(uint id, uint * x, uint * y, uint * o)
{
  t_player *	player;

  if ((player = get_player_by_id(id)) == NULL)
    return (false);
  if (x != NULL)
    *x = player->x;
  if (y != NULL)
    *y = player->y;
  if (o != NULL)
    *o = ((uint)player->direction) + 1;
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
  return (player->food);
}

