
#include	<stdio.h>
#include	<stdlib.h>
#include	"tserver.h"
#include	"server_zappy.h"

void		dbg_show_map(void)
{
  size_t	i;
  t_box *	map;

  map = get_map();
  i = 0;
  while (i < get_map_max())
    {
      printf("[%ds %dp %de %df] ",
	     get_list_len(map[i].stones),
	     get_list_len(map[i].players),
	     get_list_len(map[i].eggs),
	     map[i].food
	     );
      if (!((i + 1) % get_map_width()))
	printf("\n");
      ++i;
    }
  printf("-------------------------------------\n");
}
