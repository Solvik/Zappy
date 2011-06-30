/*
** server_zappy.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:01:37 2011 Julien Di Marco
** Last update Thu Jun 30 05:01:37 2011 Julien Di Marco
*/

#include        <strings.h>
#include        "tserver.h"
#include        "init.h"
#include        "net.h"
#include        "destroy.h"
#include        "server_zappy.h"

t_server       *gserv;

bool            server_zappy(int opt_size, char **opt)
{
  t_server      s;
  bool		out;

  out = true;
  gserv = &s;
  bzero(gserv, sizeof(*gserv));
  gserv_const(true);
  if (!init(opt_size, opt) ||
      !run())
    out = false;
  destroy(&s);
  return (out);
}
