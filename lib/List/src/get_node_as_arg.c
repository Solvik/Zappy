/*
** get_node_as_arg.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

t_node *	get_node_as_arg(t_list * list,
				bool (*match_node)(t_node *, void *),
				void * arg)
{
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  if (match_node(list->cur, arg))
	    return (list->cur);
	  list->cur = list->cur->next;
	}
    }
  return (NULL);
}

