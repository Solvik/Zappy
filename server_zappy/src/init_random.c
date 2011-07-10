/*
** init_random.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>

#include	"zopt.h"
#include	"error.h"
#include	"tserver.h"
#include	"server_zappy.h"

bool		init_random(t_zopt *opt)
{
  if (!opt)
    return (false);
#if defined(_Darwin_)
  if ((int)opt->seed == -1)
    sranddev();
  else
#endif
    srand(opt->seed);
  return (true);
}
