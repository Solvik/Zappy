/*
** error.h for Zappy in ./common/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef         ERROR_H_
# define        ERROR_H_

#  include      <stdbool.h>

bool		usage(char *);
bool            print_error(char *);
bool            print_perror(char *);
bool		syntax_print_error(char const *, ...);
void            print_warning(char *);
void            print_pwarning(char *);
void		syntax_print_warning(char const *, ...);
bool            syntax_error(char *, int);

bool		print_debug(char const *, ...);
bool		print_debug_(bool, char const *, ...);

#endif          // !ERROR_H_
