/*
** get_data_at.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:36:17 2011 Julien Di Marco
** Last update Thu Jun 30 05:36:17 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"list.h"

void *		get_data_at(t_list * list, unsigned int pos)
{
  unsigned int	i;

  if (list && (pos < list->len))
    {
      list->cur = list->begin;
      i = 0;
      while (list->cur && i < pos)
	{
	  list->cur = list->cur->next;
	  i++;
	}
      return (list->cur->data);
    }
  return (NULL);
}

