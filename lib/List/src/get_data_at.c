/*
** get_data_at.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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

