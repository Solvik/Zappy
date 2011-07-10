/*
** order_list.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
