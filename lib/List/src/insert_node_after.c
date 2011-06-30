/*
** insert_node_after.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:35:45 2011 Julien Di Marco
** Last update Thu Jun 30 05:35:45 2011 Julien Di Marco
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
