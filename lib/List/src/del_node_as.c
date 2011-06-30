/*
** del_node_as.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:39:11 2011 Julien Di Marco
** Last update Thu Jun 30 05:39:11 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"list.h"

void *		del_node_as(t_list ** list, bool (*match_node)(void *))
{
  if ((*list))
    {
      (*list)->cur = (*list)->begin;
      while ((*list)->cur)
	{
	  if (match_node((*list)->cur->data))
	    return (del_node(list, ((*list)->cur)));
	  (*list)->cur = (*list)->cur->next;
	}
    }
  return (NULL);
}
