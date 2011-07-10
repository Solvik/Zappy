/*
** del_node.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
