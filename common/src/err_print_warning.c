/*
** err_print_warning.c for Zappy in ./common/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdarg.h>
#include	<stdio.h>

void		print_warning(char *msg)
{
  fprintf(stderr, "Warning: %s\n", msg);
}

void		print_pwarning(char *cmd)
{
  perror(cmd);
}

void		syntax_print_warning(char const *format, ...)
{
   va_list arguments;

  va_start(arguments, format);
  fprintf(stderr, "Warning: ");
  vfprintf(stderr, format, arguments);
  va_end(arguments);
  fprintf(stderr, "\n");
}
