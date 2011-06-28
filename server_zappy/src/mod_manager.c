
#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"util_string.h"

#include	"tserver.h"
#include	"net.h"
#include	"network.h"
#include	"module.h"

extern t_server	*gserv;

static bool	mod_unique(void *elem, void *arg)
{
  bool	out;
  char	*lower;

  out = false;
  if (!arg)
    return (false);
  if (elem && (lower = ((t_module*)elem)->name) &&		\
      (lower = lowercase(lower)) && (strcmp(arg, lower) == 0))
    out = true;
  free(lower);
  return (out);
}

bool		mod_register(t_module * new)
{
  int	i = -1;
  char	*lower;

  lower = NULL;
  if (!new)
    return (false);
  while (new->functions[++i].action)
    printf("Action[%d]: %p\n", i, new->functions[i].action);
  if ((foreach_arg_stop_list(get_modules(), mod_unique,	\
			     (lower = lowercase(new->name)))))
    {
      fprintf(stderr, "Zappy: Warning: Module with the same name already loaded.\n");
      return (false);
    }
  free(lower);
  if (gserv_const(false))
    net_bind(&new->port);
  if (!set_new_module(new))
    fprintf(stderr, "Zappy: error: unable to set module.\n");
  return (true);
}
