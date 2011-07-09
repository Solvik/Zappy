/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sat Jul  9 03:02:06 2011 ramnes
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"napi.h"

#include	"voir.h"
#include	"zappy_protocol.h"

static bool	prendre_action(int x, int y, char *obj)
{
  e_stone	stone;

  if ((stone = is_stone(obj)) != NONE)
    {
      if (!set_box_delstone(x, y, stone, 1))
	return (false);
    }
  else if (!strcasecmp(obj, "nourriture"))
    {
      if (!set_box_delfood(x, y, 1))
	return (false);
    }
  else
    return (false);
  return (true);
}

int		zappy_prend(t_fds *c, char *cmd)
{
  t_player	*p;
  t_generic	*data;
  char		*obj;

  if (!c || !(p = *(t_player**)c) || !cmd ||
      !(strtok(cmd, " \t")) || !(obj = strtok(NULL, " \t")) ||
      !prendre_action(p->x, p->y, obj))
    {
      sends(c, "ko");
      return (false);
    }
  if (!(data = malloc(sizeof(*data))))
    {
      data->ui1 = p->id;
      data->ui2 = get_ressource_id(obj);
      event_relative_dispatch("TakeItem", data, 0);
    }
  sends(c, "ok");
  return (true);
}
