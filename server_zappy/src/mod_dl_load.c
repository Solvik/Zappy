
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	<dlfcn.h>

#include	"error.h"
#include	"module.h"

void	*mod_dl_load(char * name)
{
  int		acces;
  char		*plus;
  void *	handle;

  acces = 0;
  plus = NULL;
  if (!name)
    return (NULL);
  if ((acces = access(name, F_OK)) != -1 && \
      (handle = dlopen(name, RTLD_NOW)))
    return (handle);
  else
    print_error((acces != -1 ? dlerror() : \
		 "Zappy: Warning module not found '.so' append."));
  if ((strcmp(&name[(strlen(name) - 3)], ".so") != 0) && \
      (plus = malloc((strlen(name) + 4) * sizeof(*name))) &&
      (plus = strcpy(plus, name)) && (plus = strcat(plus, ".so")) && \
      ((acces = access(plus, F_OK)) != -1))
    handle = dlopen(plus, RTLD_NOW);
  free(plus);
  if (acces == -1 || handle == (void*)-1)
    print_error((acces != -1 ? dlerror() : \
		 "Zappy: Warning: no module to load."));
  return (handle);
}

bool	mod_load(char *name)
{
  t_module *(*get_module)(void);
  t_module	*module;
  void		*handle;

  module = NULL;
  if (!(handle = mod_dl_load(name)))
    return (false);
  if (!(get_module = dlsym(handle, "get_module")))
    return (print_error(dlerror()));
  if (!(module = get_module()))
    return (false);
  module->handle = handle;
  if (!module->handshaking && !(module->handshaking = dlsym(handle, "handshaking")))
    print_error(dlerror());
  if (!module->update && !(module->update = dlsym(handle, "update")))
    print_error(dlerror());
  if (!module->timer && !(module->timer = dlsym(handle, "timer")))
    print_error(dlerror());
  return (mod_register(module));
}

