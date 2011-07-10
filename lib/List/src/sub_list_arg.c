/*
** sub_list_arg.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

t_list *	sub_list_arg(t_list * list,
			     bool (*function)(void *, void * arg),
			     void * arg)
{
  t_list *	sub;

  sub = NULL;
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  if (function(list->cur->data, arg))
	    if (!(put_in_list(&sub, list->cur->data)))
	      return (NULL);
	  list->cur = list->cur->next;
	}
    }
  return (sub);
}

