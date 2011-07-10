/*
** server_zappy.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include        <stdio.h>
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
  bool          out;

  out = true;
  gserv = &s;
  bzero(gserv, sizeof(*gserv));
  gserv_const(true);
  if (!init(opt_size, opt) || !run())
    out = false;
  destroy(&s);
  return (out);
}
