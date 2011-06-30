/*
** get_data_as_arg.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:36:22 2011 Julien Di Marco
** Last update Thu Jun 30 05:36:22 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"list.h"

void *		get_data_as_arg(t_list * list,
				bool (*match_data)(void *, void *),
				void * arg)
{
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  if (match_data(list->cur->data, arg))
	    return (list->cur->data);
	  list->cur = list->cur->next;
	}
    }
  return (NULL);
}

