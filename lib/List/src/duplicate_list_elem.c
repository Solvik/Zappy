/*
** duplicate_list_elem.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

t_list *	duplicate_list_elem(t_list * list, void * (*duplicate)(void *))
{
  t_list *	newlist;

  newlist = NULL;
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
        {
	  if (!(put_in_list(&newlist,
			    (duplicate ?
			     duplicate(list->cur->data)
			     : list->cur->data))))
	    return (NULL);
          list->cur = list->cur->next;
        }
    }
  return (newlist);
}

