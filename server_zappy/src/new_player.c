
#include	<stdlib.h>
#include	<strings.h>
#include	<time.h>
#include	"tserver.h"
#include	"conf.h"
#include	"player.h"

static t_player *init_player(void)
{
  static uint	id = 0;
  t_player 	*player;

  if (!(player = malloc(sizeof(*player))))
    return (NULL);
  bzero(player, sizeof(*player));
  player->id = id;
  player->level = default_level;
  player->food = default_life;
  player->x = rand() % get_map_width();
  player->y = rand() % get_map_height();
  player->stones = NULL;
  player->direction = rand() % (WEST + 1);
  ++id;
  return (player);
}

t_player *	new_player(char * team)
{
  t_player *	player;

  if (!(player = init_player()) ||
    !(set_box_addplayer(player, team,
			rand() % get_map_width(),
			rand() % get_map_height())))
    return (NULL);
  return (player);
}
