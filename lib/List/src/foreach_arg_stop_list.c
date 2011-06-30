/*
** foreach_arg_stop_list.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:36:48 2011 Julien Di Marco
** Last update Thu Jun 30 05:36:48 2011 Julien Di Marco
*/

#include	"list.h"

bool		foreach_arg_stop_list(t_list * list,
				      bool (*function)(void *, void *),
				      void * arg)
{
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  if (function(list->cur->data, arg))
	    return (true);
	  list->cur = list->cur->next;
	}
    }
  return (false);
}

