/*
** gserv_setbox_addegg.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/modules/zappy_protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 20:45:10 2011 solvik blum
** Last update Sun Jul  3 22:43:53 2011 solvik blum
*/

#include		<stdlib.h>

#include		"egg.h"
#include		"tserver.h"

extern t_server		*gserv;

static t_egg		*new_egg(t_player *player)
{
  t_egg 		*egg;

  if (!(egg = malloc(sizeof(*egg))))
    return (NULL);
  egg->x = player->x;
  egg->y = player->y;
  egg->status = GROWING;
  egg->team = get_team_of_player(player);
  return (egg);
}

t_egg			*setbox_add_egg(t_player *player)
{
  t_box 		*box;
  t_egg 		*egg;

  if (!(box = get_box(player->x, player->y)))
    return (NULL);
  if (!(egg = new_egg(player)) ||
      !put_in_list(&(box->eggs), egg))
    return (NULL);
  return (egg);
}

