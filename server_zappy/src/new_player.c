
#include	<stdlib.h>
#include	<strings.h>
#include	"conf.h"
#include	"player.h"

t_player *	new_player(void)
{
  t_player *	player;

  if (!(player = malloc(sizeof(*player))))
    return (NULL);
  bzero(player, sizeof(*player));
  player->level = 1;
  player->life = default_life;
  player->x = 0;
  player->y = 0;
  player->stones = NULL;
  player->direction = EAST;
  return (player);
}
