
#include	<strings.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<stdio.h>

#include	"conf.h"
#include	"zopt.h"
#include	"map.h"
#include	"server_zappy.h"

static void	init_opt_default(t_zopt	*optab)
{
  bzero(optab, sizeof(*optab));
  optab->port = default_port;
  optab->nb_client = default_nb_client;
  optab->delay = default_delay;
  optab->time = default_time;
  optab->width = default_width;
  optab->height = default_height;
}

static bool	options(char opt, t_zopt *optab)
{
  if (opt == 't')
    optab->delay = strtoul(optarg, NULL, 0);
  else if (opt == 'c')
    optab->nb_client = strtoul(optarg, NULL, 0);
  else if (opt == 'p')
    optab->port = strtoul(optarg, NULL, 0);
  else if (opt == 'r')
    optab->time = strtoul(optarg, NULL, 0);
  else if (opt == 'w')
    optab->width = strtoul(optarg, NULL, 0);
  else if (opt == 'h')
    optab->height = strtoul(optarg, NULL, 0);
  else if (opt == '?')
    return (false);
  return (true);
}

static void	epure(t_zopt *optab)
{
  if (optab->time <= 0)
    optab->time = default_time;
  if (optab->delay <= 0)
    optab->delay = default_delay;
}

bool		init_opt(int ac, char *opt[], t_zopt *optab)
{
  char		option;

  init_opt_default(optab);
  while ((option = getopt(ac, opt, "c:p:t:r:w:h:")) != -1)
    if ((!options(option, optab)))
      {
	fprintf(stderr, "Usage: %s bla bla bla\n", (opt ? opt[0] : "Zappy"));
	return (false);
      }
  epure(optab);
  return (true);
}
