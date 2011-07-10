/*
** napi_functions.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"module.h"

bool		command_add(t_mod_func *f, char *cmd, void *a)
{
  if (!f || !cmd || !a)
    return (false);
  while (f && (*f).action)
    f = &f[1];
  (*f).command = strdup(cmd);
  (*f).delay = -1;
  (*f).action = a;
  return (true);
}

bool		command_relative(t_mod_func *f, char *cmd, void *a, double d)
{
  if (!f || !cmd || !a)
    return (false);
  while (f && (*f).action)
    f = &f[1];
  (*f).command = strdup(cmd);
  (*f).delay = (d >= 0.0 ? d : -1);
  (*f).relative = true;
  (*f).action = a;
  return (true);
}

bool		command_universel(t_mod_func *f, char *cmd, void *a, double d)
{
  if (!f || !cmd || !a)
    return (false);
  while (f && (*f).action)
    f = &f[1];
  (*f).command = strdup(cmd);
  (*f).delay = (d >= 0.0 ? d : -1);
  (*f).relative = false;
  (*f).action = a;
  return (true);
}
