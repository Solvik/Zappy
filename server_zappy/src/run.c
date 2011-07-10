/*
** run.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include        <stdbool.h>
#include        <stdio.h>
#include        <time.h>

#include        "time_.h"

#include        "net.h"
#include        "run.h"
#include        "exec.h"
#include        "tserver.h"
#include	"dbg.h"

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
