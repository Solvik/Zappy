/*
** insert_node_before.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:35:28 2011 Julien Di Marco
** Last update Thu Jun 30 05:35:28 2011 Julien Di Marco
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
