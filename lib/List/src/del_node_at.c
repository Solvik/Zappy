/*
** del_node_at.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

void *		del_node_at(t_list ** list, unsigned int pos)
{
  return (del_node(list, get_node_at(*list, pos)));
}
