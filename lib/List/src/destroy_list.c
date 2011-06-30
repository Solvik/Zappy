/*
** destroy_list.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:38:59 2011 Julien Di Marco
** Last update Thu Jun 30 05:38:59 2011 Julien Di Marco
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
