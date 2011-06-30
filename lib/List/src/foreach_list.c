/*
** foreach_list.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:36:40 2011 Julien Di Marco
** Last update Thu Jun 30 05:36:40 2011 Julien Di Marco
*/

#include	"list.h"

void		foreach_list(t_list * list, void (*function)(void *))
{
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  function(list->cur->data);
	  list->cur = list->cur->next;
	}
    }
}

