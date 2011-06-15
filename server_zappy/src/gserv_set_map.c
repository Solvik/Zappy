
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server *	gserv;

void		set_map_width(uint width)
{
  gserv->map.width = width;
}

void		set_map_height(uint height)
{
  gserv->map.height = height;
}

void		set_map(t_box * map)
{
  gserv->map.map = map;
}
