/*
** time.c for  in /home/di-mar_j/git/Zappy/server_zappy
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Tue Jun 28 23:38:00 2011 julien di-marco
** Last update Tue Jun 28 23:38:00 2011 julien di-marco
*/

#include	<sys/time.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"time_.h"


double		time_(void)
{
  time__	t;

  if (gettimeofday(&t, NULL) != 0)
    return (0.0);
  return (timeval__(&t));
}

double		time_d(double time)
{
  return (time_() - time);
}

double		timeval__(time__ *t)
{
  return (!t ? 0.0 : (t->tv_sec + (t->tv_usec / 1000000.0)));
}

time__		*timeval_(time__ *t, double time)
{
  if (!t || time < 0)
    return (t);
  t->tv_sec = time / 1;
  t->tv_usec = (time - t->tv_sec) * 1000000.0;
  return (t);
}
