
#include	<fcntl.h>
#include	<dlfcn.h>
#include	"error.h"
#include	"module.h"

t_module *	mod_dl_load(char * name)
{
  void *	handle;
  t_module *	new_module;
  t_module *	(*get_module)(void);

  if (!(handle = dlopen(name, RTLD_NOW)))
    return ((t_module *)print_error(dlerror()));
  if (!(get_module = dlsym(handle, "get_module")))
    return ((t_module *)print_error(dlerror()));
  if (!(new_module = get_module()))
    return (false);
  new_module->handle = handle;
  if (!(new_module->functions.action = dlsym(handle, "action")))
    return ((t_module *)print_error(dlerror()));
  /* do the same for the other functions */
  return (new_module);
}
