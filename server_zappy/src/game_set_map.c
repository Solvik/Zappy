
#include	"game.h"
#include	"server_zappy.h"

extern t_game *	game;

void		set_map_width(uint width)
{
  game->map.width = width;
}

void		set_map_height(uint height)
{
  game->map.height = height;
}

void		set_map(t_box * map)
{
  game->map.map = map;
}
