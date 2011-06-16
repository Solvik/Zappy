
#include		<stdlib.h>
#include		"module.h"

static bool		mod_manager(e_module_action action,
				    t_module * new_module,
				    t_list ** list)
{
  static t_list *	modules = NULL;

  if (action == ADD)
    {
      if (!(put_in_list(&modules, new_module)))
	return (false);
    }
  else if (action == GET)
    *list = modules;
  return (true);
}

bool			mod_add(t_module * new_module)
{
  return (mod_manager(ADD, new_module, NULL));
}

t_list *		mod_get(void)
{
  t_list *		modules;

  mod_manager(GET, NULL, &modules);
  return (modules);
}
