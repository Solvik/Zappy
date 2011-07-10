/*
** insert_data_before.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

bool		insert_data_before(t_list * list, t_node * node, void * data)
{
  t_node *	new;

  if ((new = new_node(data)))
    {
      if ((insert_node_before(list, node, new)))
	return (true);
      free(new);
    }
  return (false);
}

