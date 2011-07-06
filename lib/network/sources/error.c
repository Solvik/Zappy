/*
** error.c for  in /home/di-mar_j/git/Zappy/lib/network/sources
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jul  6 03:54:30 2011 julien di-marco
** Last update Wed Jul  6 03:54:30 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdarg.h>
#include	<stdio.h>

#include	"network.h"

void		error(char const *format, ...)
{
  va_list arguments;

  va_start(arguments, format);
#if defined(ERRORMSG)
  fprintf(stderr, "Pool: ");
  vfprintf(stderr, format, arguments);
#endif
  va_end(arguments);
#if defined(ERRORMSG)
  fprintf(stderr, "\n");
#endif
}
