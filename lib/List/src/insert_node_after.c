/*
** insert_node_after.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"list.h"

bool		insert_node_after(t_list * list,
				  t_node * node,
				  t_node * new)
{
  if (list && node && new)
    {
      if (node->next)
	node->next->prev = new;
      new->next = node->next;
      node->next = new;
      new->prev = node;
      return (true);
    }
  return (false);
}
