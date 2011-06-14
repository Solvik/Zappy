/*
** error.h for My IRC in myirc/src_server/include
** 
** Made by lepage_b
** Login   <lepage_b@epitech.net>
** 
** Started on  Sat Mar 19 16:43:54 2011 lepage_b
** Last update Tue Apr 05 17:47:17 2011 lepage_b
*/

#ifndef		ERROR_H_
# define	ERROR_H_

#  include	<stdbool.h>

bool		print_error(char *);
bool		print_perror(char *);
void		print_warning(char *);
void		print_pwarning(char *);
bool		syntax_error(char *, int);

#endif		// !ERROR_H_
