
#include		<stdlib.h>
#include		"tserver.h"

bool			setplayer_addfood(uint id, uint nb)
{
  t_player *		player;

  if (!(player = get_player_by_id(id)))
    return (false);
  player->food += nb;
  return (true);
}
