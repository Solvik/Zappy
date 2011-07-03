
#include		<stdlib.h>
#include		"tserver.h"

uint		get_box_nbfood(uint x, uint y)
{
  t_box 	*box;

  if (!(box = get_box(x, y)))
    return (0);
  return (box->food);
}
