/*
** gserv_setbox_addegg.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/modules/zappy_protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 20:45:10 2011 solvik blum
** Last update Fri Jul  8 09:49:00 2011 ramnes
*/

#include		<stdlib.h>

#include		"egg.h"
#include		"tserver.h"

extern t_server		*gserv;

static t_egg		*new_egg(t_player *player, uint id)
{
  t_egg 		*egg;

  if (!player || !(egg = calloc(1, sizeof(*egg))))
    return (NULL);
  egg->id = id;
  egg->idf = player->id;
  egg->x = player->x;
  egg->y = player->y;
  egg->status = GROWING;
  egg->father = player;
  egg->team = get_team_of_player(player);
  put_in_list(&gserv->egg, egg);
  return (egg);
}

t_egg			*set_box_addegg(t_player *player)
{
  t_player		*p;
  t_box 		*box;
  t_egg 		*egg;

  if (!player || !(box = get_box(player->x, player->y)))
    return (NULL);
  if (!player->team || !(p = init_player(player->team)))
    return (NULL);
  player->team->max_conn += 1;
  p->x = player->x;
  p->y = player->y;
  if (!(egg = new_egg(player, p->id)) ||
      !put_in_list(&(box->eggs), egg))
    return (NULL);
  egg->himself = p;
  return (egg);
}
