
#include		<stdlib.h>
#include		"tserver.h"

bool			setplayer_delfood(uint id, uint nb)
{
  t_player *		player;

  if (!(player = get_player_by_id(id)))
    return (false);
  if (player->food < nb)
    player->food = 0;
  else
    player->food -= nb;
  return (true);
}
