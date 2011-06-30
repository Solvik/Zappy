/*
** order_list.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:35:13 2011 Julien Di Marco
** Last update Thu Jun 30 05:35:13 2011 Julien Di Marco
*/

#include	"list.h"

void		order_list(t_list * list, bool (*compare_data)(void *, void *))
{
  t_node *	tmp;

  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  tmp = list->cur;
	  while (tmp)
	    {
	      if (tmp->prev && compare_data(tmp->data, tmp->prev->data))
		swap_data(tmp, tmp->prev);
	      tmp = tmp->prev;
	    }
	  list->cur = list->cur->next;
	}
    }
}
