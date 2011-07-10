/*
** itoa.h for Zappy in ./lib/itoa/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		ITOA_H_
# define	ITOA_H_

#  define	abs(val)	((val >= 0) ? val : -val)
#  define	RADIX		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

size_t		itoa_number_size(int input, int radix);

void		itoa(int input, char *buffer, int radix);
char		*itoadup(int input, int radix);

#endif		/* !ITOA_H_ */
