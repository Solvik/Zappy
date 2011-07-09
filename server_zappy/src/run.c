/*
** run.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:01:56 2011 Julien Di Marco
** Last update Sat Jul  9 18:41:24 2011 solvik blum
*/

#include        <stdbool.h>
#include        <stdio.h>
#include        <time.h>

#include        "time_.h"

#include        "net.h"
#include        "run.h"
#include        "exec.h"
#include        "tserver.h"
#include "dbg.h"

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
      exec_updates(time_d(t));
      exec_pool(gserv->pool, time_d(t));
      exec_event(time_d(t));
      exec_timer(&tv, time_d(t));
#if	!defined(NDEBUG) && defined(MAPPRINT)
      dbg_show_map();
#endif
    }
  return (true);
}
