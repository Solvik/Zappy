/*
** sub_list_arg.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:34:47 2011 Julien Di Marco
** Last update Thu Jun 30 05:34:47 2011 Julien Di Marco
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

