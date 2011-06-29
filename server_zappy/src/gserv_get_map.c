
#include	<stdlib.h>
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server *	gserv;

uint		get_map_width(void)
{
  return (gserv->map.width);
}

uint		get_map_height(void)
{
  return (gserv->map.height);
}

t_box *		get_map(void)
{
  return (gserv->map.map);
}

uint		get_map_max(void)
{
  return (get_map_height() * get_map_width());
}

t_box *		get_box(uint x, uint y)
{
  if (x >= get_map_height() || y >= get_map_width())
    return (NULL);
  return (&(gserv->map.map[x + (get_map_width() * y)]));
}

t_box *		get_box_at(uint i)
{
  if (i < get_map_max())
    return (NULL);
  return (&(gserv->map.map[i]));
}

