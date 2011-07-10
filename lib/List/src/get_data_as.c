/*
** get_data_as.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

void *		get_data_as(t_list * list, bool (*match_data)(void *))
{
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  if (match_data(list->cur->data))
	    return (list->cur->data);
	  list->cur = list->cur->next;
	}
    }
  return (NULL);
}

