/*
** itoa_number_size.c for My IRC in myirc/lib/libitoa/src
** 
** Made by lepage_b
** Login   <lepage_b@epitech.net>
** 
** Started on  Thu Apr 07 22:05:40 2011 lepage_b
** Last update Sun Apr 24 23:09:03 2011 lepage_b
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
