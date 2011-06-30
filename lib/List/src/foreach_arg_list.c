/*
** foreach_arg_list.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:38:36 2011 Julien Di Marco
** Last update Thu Jun 30 05:38:36 2011 Julien Di Marco
*/

#include	"list.h"

void		foreach_arg_list(t_list * list,
				 void (*function)(void * elem, void * arg),
				 void * arg)
{
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  function(list->cur->data, arg);
	  list->cur = list->cur->next;
	}
    }
}

