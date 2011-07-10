/*
** put_in_list.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<strings.h>
#include	<stdlib.h>
#include	"list.h"

static bool	list_init(t_list ** list, void * data)
{
  t_node *	new;

  if (!(*list = malloc(sizeof(**list)))
      || !(new = new_node(data)))
    return (false);
  bzero(*list, sizeof(**list));
  (*list)->len = 1;
  (*list)->begin = new;
  (*list)->end = new;
  return (true);
}

bool		put_in_list(t_list ** list, void * data)
{
  t_node *	new;

  if (!list)
    return (false);
  if (!*list)
    return (list_init(list, data));
  if (!(new = new_node(data)))
    return (false);
  (*list)->end->next = new;
  new->prev = (*list)->end;
  (*list)->end = new;
  ++((*list)->len);
  return (true);
 }
