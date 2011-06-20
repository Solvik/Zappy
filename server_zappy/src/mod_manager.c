
#include		<strings.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<string.h>
#include		<ctype.h>
#include		<stdio.h>

#include		"tserver.h"
#include		"network.h"
#include		"module.h"

extern t_server		*gserv;

static char		*lowercase(char *s)
{
  size_t	i;
  char		*p;

  i = 0;
  p = NULL;
  if ((p = strdup(s)))
    while (p && p[i])
      {
	p[i] = tolower(p[i]);
	i += 1;
      }
  return (p);
}

static bool		mod_unique(void *elem, void *arg)
{
  bool	out;
  char	*lower;

  out = false;
  if (!arg)
    return (false);
  if (elem && (lower = ((t_module*)elem)->name) &&		\
      (lower = lowercase(lower)) && (strcmp(arg, lower) == 0))
    {
      fprintf(stderr, "Found %s - %s\n", (char*)arg, lower);
      out = true;
    }
  free(lower);
  return (out);
}

bool			mod_register(t_module * new)
{
  char	*lower;

  lower = NULL;
  if (!new)
    return (false);
  printf("return: %d\n", foreach_arg_stop_list(get_modules(), mod_unique, (lower = lowercase(new->name))));
  if ((foreach_arg_stop_list(get_modules(), mod_unique, \
			      (lower = lowercase(new->name)))))
    {
      fprintf(stderr, "Zappy: Warning: Module with the same name already loaded.\n");
      return (false);
    }
  free(lower);
  if (gserv_const(false))
    if (add_socket(&gserv->pool, new->port, 10) == -1)
      {
	fprintf(stderr, "Zappy: Warning: Can't open network acording to module.\n");
	return (false);
      }
  if (!set_new_module(new))
    fprintf(stderr, "Zappy: error: unable to set module.\n");
  return (true);
}
