/*
** run.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:01:56 2011 Julien Di Marco
** Last update Thu Jun 30 05:01:56 2011 Julien Di Marco
*/

#include        <stdbool.h>
#include        <stdio.h>
#include        <time.h>

#include        "time_.h"

#include        "net.h"
#include        "run.h"
#include        "exec.h"
#include        "tserver.h"

extern t_server *gserv;

bool            run(void)
{
  time__        *tv;
  _time         t;

  tv = NULL;
  while (!run_end())
    {
      t = time_();
      pool(&gserv->pool, tv);
      printf("Updates: T[%f] d[%f]\n", t, time_d(t));
      exec_pool(gserv->pool, time_d(t));
      exec_timer(&tv, time_d(t));
    }
  return (true);
}
