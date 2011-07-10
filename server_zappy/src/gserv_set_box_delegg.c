
#include	<stdlib.h>
#include	"egg.h"
#include	"map.h"
#include	"tserver.h"

bool		match_egg(void * data, void * arg)
{
  return (data == arg);
}

void		set_box_delegg(t_egg * egg)
{
  t_box *	box;

  if (!(box = get_box(egg->x, egg->y)) ||
      !del_node_as_arg(&box->eggs, match_egg, egg))
    return ;
  free(egg);
}
