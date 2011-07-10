/*
** itoa_number_size.c for Zappy in ./lib/itoa/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>

size_t		itoa_number_size(int input, int radix)
{
  size_t	i;

  i = 1;
  if (input < 0)
    ++i;
  while ((input /= radix))
    ++i;
  return (i);
}
