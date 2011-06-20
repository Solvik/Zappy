
#include	"tserver.h"
#include	"zopt.h"
#include	"module.h"

static void	init_module_insert(void * data)
{
  mod_load((char *)data);
}

/*
**
** if a Module don't load - no prob.
** it'll just not register
** but it'l work if at least one module load successfully.
**
*/

bool		init_modules(t_zopt * optab)
{
  foreach_list(optab->module, init_module_insert);
  return (true);
}
