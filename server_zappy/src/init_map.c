
#include	"map.h"
#include	"zopt.h"
#include	"server_zappy.h"

bool		init_map(t_map * map, t_zopt *opt)
{
  map->width = opt->width;
  map->height = opt->height;
  (void)map;
  return (true);
}
