
#include	"zopt.h"
#include	"tserver.h"

extern t_server *	gserv;

bool		init_names(t_zopt * opt)
{
  gserv->names.modules = opt->module;
  gserv->names.teams = opt->team;
  return (true);
}
