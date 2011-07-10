/*
** destroy_list.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

void		destroy_list(t_list ** list, void (*destroy_elem)(void *))
{
  t_node *	tmp;

  if ((*list))
    {
      (*list)->cur = (*list)->begin;
      while ((*list)->cur)
	{
	  if (destroy_elem)
	    destroy_elem((*list)->cur->data);
	  tmp = (*list)->cur->next;
	  free((*list)->cur);
	  (*list)->cur = tmp;
	}
      free((*list));
    }
  *list = NULL;
}
