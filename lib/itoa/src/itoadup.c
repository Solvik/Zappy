/*
** itoadup.c for My IRC in myirc/lib/libitoa/src
** 
** Made by lepage_b
** Login   <lepage_b@epitech.net>
** 
** Started on  Thu Apr 07 22:05:40 2011 lepage_b
** Last update Sun Apr 24 23:09:03 2011 lepage_b
*/

#include	<stdlib.h>
#include	"itoa.h"

char		*itoadup(int input, int radix)
{
  size_t	i;
  char		*buffer;

  if (radix >= (int)sizeof(RADIX) ||
      !(buffer = malloc(sizeof(*buffer)
			* ((i = itoa_number_size(input, radix) - 1) + 2))))
    return (NULL);
  buffer[i] = '\0';
  if (input < 0)
    buffer[0] = '-';
  while ((input))
    {
      buffer[i] = RADIX[abs(input) % radix];
      input /= radix;
      --i;
    }
  return (buffer);
}
