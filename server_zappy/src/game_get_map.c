
#include	"game.h"
#include	"server_zappy.h"

extern t_game *	game;

uint		get_map_width(void)
{
  return (game->map.width);
}

uint		get_map_height(void)
{
  return (game->map.height);
}
