
#include		<stdlib.h>
#include		"stone.h"
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

static bool	match_stone(void *data, void *stone)
{
  return (((t_stone *)data)->type == *((e_stone *)stone));
}

uint		get_player_nbstones(uint id, e_stone type)
{
  t_player	*player;
  t_stone 	*stone;

  if (!(player = get_player_by_id(id)) ||
      !(stone = get_data_as_arg(player->stones, match_stone, &type)))
    return (0);
  return (stone->nb);
}
