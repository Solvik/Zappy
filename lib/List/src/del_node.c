/*
** del_node.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:39:20 2011 Julien Di Marco
** Last update Thu Jun 30 05:39:20 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"list.h"

void *		del_node(t_list ** list, t_node * node)
{
  void *	data;

  if ((*list) && node)
    {
      if (node->prev)
	node->prev->next = node->next;
      else
	(*list)->begin = node->next;
      if (node->next)
	node->next->prev = node->prev;
      else
	(*list)->end = node->prev;
      data = node->data;
      free(node);
      --((*list)->len);
      if (!((*list)->len))
	{
	  free(*list);
	  *list = NULL;
	}
      return (data);
    }
  return (NULL);
}
