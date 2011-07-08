/*
** gserv_add_player.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:05:45 2011 Julien Di Marco
** Last update Mon Jul  4 15:57:27 2011 Sebastien Blot
*/

#include		<stdlib.h>
#include		<string.h>
#include		"tserver.h"
#include		"player.h"
#include		"team.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

bool		set_box_addplayer(t_player *player, uint x, uint y)
{
  t_box		*box;

  if (!player || !(box = get_box(x, y)) ||
      !put_in_list(&box->players, player))
    return (false);
  return (true);
}
