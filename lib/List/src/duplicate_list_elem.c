/*
** duplicate_list_elem.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:38:42 2011 Julien Di Marco
** Last update Thu Jun 30 05:38:42 2011 Julien Di Marco
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

