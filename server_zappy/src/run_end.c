
#include	"ztypes.h"
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server	*gserv;

bool		run_end(void)
{
  return (!(get_list_len(gserv->module) > 0 ));
}
