/*
** del_all_node_as_arg.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:39:24 2011 Julien Di Marco
** Last update Thu Jun 30 05:39:24 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"list.h"

void		del_all_node_as_arg(t_list ** list,
				    bool (*match_node)(void *, void *),
				    void (*destroy_data)(void *),
				    void * arg)
{
  void *	data;

  while ((data = del_node_as_arg(list, match_node, arg)))
    if (destroy_data)
      destroy_data(data);
}
