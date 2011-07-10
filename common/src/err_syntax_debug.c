/*
** err_syntax_debug.c for Zappy in ./common/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdarg.h>
#include	<stdio.h>
#include	"error.h"

bool		print_debug(char const *format, ...)
{
#if !defined(NDEBUG)
  va_list arguments;

  va_start(arguments, format);
  fprintf(stderr, "Debug: ");
  vfprintf(stderr, format, arguments);
  va_end(arguments);
  fprintf(stderr, "\n");
  return (true);
#else
  (void)format;
  return (false);
#endif
}

bool		print_debug_(bool a, char const *format, ...)
{
#if !defined(NDEBUG)
  va_list arguments;

  va_start(arguments, format);
  if (a)
    fprintf(stderr, "Debug: ");
  vfprintf(stderr, format, arguments);
  va_end(arguments);
  return (true);
#else
  (void)a;
  (void)format;
  return (false);
#endif
}

