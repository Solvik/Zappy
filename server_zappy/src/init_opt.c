/*
** init_opt.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:04:46 2011 Julien Di Marco
** Last update Thu Jun 30 05:04:46 2011 Julien Di Marco
*/

#include	<strings.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<stdio.h>
#include	<time.h>

#include	"error.h"
#include	"conf.h"
#include	"zopt.h"
#include	"map.h"
#include	"server_zappy.h"

#include	"tserver.h"

static void	init_opt_default(t_zopt	*optab)
{
  bzero(optab, sizeof(*optab));
  set_port(optab->port = default_port);
  optab->nb_clients = default_nb_clients;
  set_delay(optab->delay = default_delay);
  set_time(optab->time = default_time);
  optab->width = default_width;
  optab->height = default_height;
  optab->seed = time(NULL);
}

static bool	multiple(char *opts[], t_list **list)
{
  int		tmp;

  tmp = optind - 1;
  while ((tmp) && opts[tmp] && opts[tmp][0] != '-')
    if (!(put_in_list(list, strdup(opts[tmp++]))))
      return (false);
  return (true);
}

static bool	options(char opt, char *opts[], t_zopt *optab,
			char * path)
{
  if (opt == 't')
    optab->delay = strtod(optarg, NULL);
  else if (opt == 'c')
    optab->nb_clients = strtoul(optarg, NULL, 0);
  else if (opt == 'p')
    optab->port = strtoul(optarg, NULL, 0);
  else if (opt == 'r')
    optab->time = strtod(optarg, NULL);
  else if (opt == 'w')
    optab->width = strtoul(optarg, NULL, 0);
  else if (opt == 'x')
    optab->width = strtoul(optarg, NULL, 0);
  else if (opt == 'h')
    optab->height = strtoul(optarg, NULL, 0);
  else if (opt == 'y')
    optab->height = strtoul(optarg, NULL, 0);
  else if (opt == 's')
    optab->seed = strtoul(optarg, NULL, 0);
  else if (opt == 'n')
    multiple(opts, &optab->team);
  else if (opt == 'm')
    multiple(opts, &optab->module);
  else if (opt == 'u')
    return (usage(path));
  else if (opt == '?')
    return (false);
  return (true);
}

static bool	epure(t_zopt *optab, char * path)
{
  if (optab->time <= 0)
    {
      print_warning("Invalid time.");
      optab->time = default_time;
    }
  if (optab->delay <= 0)
    {
      print_warning("Invalid delay.");
      optab->delay = default_delay;
    }
  if (get_list_len(optab->team) < 2)
    return (usage(path));
  return (true);
}

bool		init_opt(int ac, char *opt[], t_zopt *optab)
{
  char		option;

  init_opt_default(optab);
  while ((option = getopt(ac, opt, "us:c:p:t:r:w:h:x:y:n:m:")) != -1)
    if ((!options(option, opt, optab, *opt)))
      return (usage(*opt));
  return (epure(optab, *opt));
}
