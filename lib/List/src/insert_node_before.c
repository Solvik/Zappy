/*
** insert_node_before.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"list.h"

bool		insert_node_before(t_list * list,
				   t_node * node,
				   t_node * new)
{
  if (list && node && new)
    {
      if (node->prev)
	node->prev->next = new;
      new->prev = node->prev;
      node->prev = new;
      new->next = node;
      return (true);
    }
  return (false);
}
