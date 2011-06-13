
#include	<strings.h>
#include	"conf.h"
#include	"zopt.h"
#include	"map.h"
#include	"server_zappy.h"

static void	init_opt_default(t_zopt * optab, t_map * map)
{
  bzero(optab, sizeof(*optab));
  optab->port = default_port;
  optab->nb_client = default_nb_client;
  optab->delay = default_delay;
  map->width = default_width;
  map->width = default_height;
}

bool		init_opt(char ** opt, t_map * map, t_zopt * optab)
{
  init_opt_default(optab, map);
  (void)opt;
  // get arguments with getopt() to replace default values if necessary
  return (true);
}
