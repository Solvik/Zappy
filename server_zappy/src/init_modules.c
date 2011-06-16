
#include	"tserver.h"
#include	"zopt.h"
#include	"module.h"

static void	init_module_insert(void * data, void * arg)
{
  t_module *	new_module;

  if (!(new_module = mod_dl_load((char *)data)))
    {
      *((bool *)arg) = true;
      return ;
    }
  if (!set_new_module(new_module))
      *((bool *)arg) = true;
}

bool		init_modules(t_zopt * optab)
{
  bool		error;

  error = false;
  foreach_arg_list(optab->module, init_module_insert, &error);
  if (error)
    return (false);
  return (true);
}
