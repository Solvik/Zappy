
#include	"tserver.h"

extern t_server *	gserv;

bool		set_new_module(t_module * module)
{
  return (put_in_list(&gserv->module, module));
}

t_list *	get_modules(void)
{
  return (gserv->module);
}
