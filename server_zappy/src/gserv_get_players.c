
#include		<stdlib.h>
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server *	gserv;

t_list *		get_players(uint x, uint y)
{
  t_box *		box;

  if (!(box = get_box(x, y)))
    return (false);
  return (box->players);
}
