/*
** prend.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"napi.h"

#include	"voir.h"
#include	"zappy_protocol.h"

static bool	prendre_action(t_player *p, char *obj)
{
  e_stone	stone;

  if ((stone = is_stone(obj)) != NONE)
    {
      if (!set_box_delstone(p->x, p->y, stone, 1) ||
	  !set_player_addstone(p, stone, 1))
	return (false);
    }
  else if (!strcasecmp(obj, "nourriture"))
    {
      if (!set_box_delfood(p->x, p->y, 1) ||
	  !set_player_addfood(p->id, 1))
	return (false);
    }
  else
    return (false);
  return (true);
}

int		zappy_prend(t_fds *client, char *cmd)
{
  t_player	*p;
  t_generic	data;
  char		*obj;

  if (!client || !(p = *(t_player**)client) || !cmd ||
      !(strtok(cmd, " \t")) || !(obj = strtok(NULL, " \t")) ||
      !prendre_action(p, obj))
    {
      sends(client, "ko");
      return (false);
    }
  data.ui1 = get_ressource_id(obj);
  data.client = client;
  event_relative_dispatch("TakeItem", &data, 0);
  sends(client, "ok");
  return (true);
}
