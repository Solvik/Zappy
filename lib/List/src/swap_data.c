/*
** swap_data.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:34:41 2011 Julien Di Marco
** Last update Thu Jun 30 05:34:41 2011 Julien Di Marco
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

