/*
** itoa.c for Zappy in ./lib/itoa/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>

#include	"itoa.h"

void		itoa(int input, char *buffer, int radix)
{
  size_t	i;

  i = itoa_number_size(input, radix) - 1;
  buffer[i] = '\0';
  if (input < 0)
    buffer[0] = '-';
  while ((input))
    {
      buffer[i] = RADIX[abs(input) % radix];
      input /= radix;
      --i;
    }
}
