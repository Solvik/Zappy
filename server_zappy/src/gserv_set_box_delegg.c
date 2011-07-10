/*
** gserv_set_box_delegg.c for  in /home/solvik/tek2/proj/Zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul 10 16:34:09 2011 solvik blum
** Last update Sun Jul 10 16:34:10 2011 solvik blum
*/

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
