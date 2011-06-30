/*
** del_all_node_as.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:39:27 2011 Julien Di Marco
** Last update Thu Jun 30 05:39:27 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"list.h"

void		del_all_node_as(t_list ** list,
				bool (*match_node)(void *),
				void (*destroy_data)(void *))
{
  void *	data;

  while ((data = del_node_as(list, match_node)))
    if (destroy_data)
      destroy_data(data);
}
