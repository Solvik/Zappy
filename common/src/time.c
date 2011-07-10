/*
** time.c for Zappy in ./common/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
