/*
** exec_timer.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 29 01:07:29 2011 julien di-marco
** Last update Wed Jun 29 01:07:29 2011 julien di-marco
*/

#include	<stdbool.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"time_.h"
#include	"scheduler.h"

bool		exec_timer(time__ **tv, double tdt)
{
  static time__	*t = NULL;
  double	lol;

  (void)tdt;
  if (!tv || (!t && !(t = calloc(1, sizeof(*t)))))
    return (false);
  *tv = timeval_(t, (lol = (scheduler_update(-1.0))));
  if (lol <= -1.0)
    *tv = NULL;
  return (true);
}
