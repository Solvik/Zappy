/*
** itoa.h for My IRC in myirc/lib/libitoa/include
** 
** Made by lepage_b
** Login   <lepage_b@epitech.net>
** 
** Started on  Thu Apr 07 22:05:40 2011 lepage_b
** Last update Sun Apr 24 23:09:03 2011 lepage_b
*/

#ifndef		ITOA_H_
# define	ITOA_H_

#  define	abs(val)	((val >= 0) ? val : -val)
#  define	RADIX		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

size_t		itoa_number_size(int input, int radix);

void		itoa(int input, char *buffer, int radix);
char		*itoadup(int input, int radix);

#endif		/* !ITOA_H_ */
