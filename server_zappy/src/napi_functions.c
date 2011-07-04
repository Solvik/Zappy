/*
** napi_functions.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 29 02:05:21 2011 julien di-marco
** Last update Wed Jun 29 02:05:21 2011 julien di-marco
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
