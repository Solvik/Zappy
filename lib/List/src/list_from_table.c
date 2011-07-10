/*
** list_from_table.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"list.h"

t_list *	list_from_table(char ** table)
{
  t_list *	list;
  ssize_t	i;

  list = NULL;
  i = 0;
  while (table && table[i])
    {
      if (!(put_in_list(&list, table[i])))
	return (NULL);
      ++i;
    }
  return (list);
}
