/*
** swap_data.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"list.h"

void		swap_data(t_node * left, t_node * right)
{
  void *	tmp;

  if (right && left)
    {
      tmp = right->data;
      right->data = left->data;
      left->data = tmp;
    }
}

