/*
** gserv_setbox_delfood.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 16:04:23 2011 solvik blum
** Last update Sun Jul  3 17:26:36 2011 solvik blum
*/


#include		<stdlib.h>
#include		"stone.h"
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

bool			setbox_addfood(uint x, uint y, uint nb)
{
  t_box 		*box;
  t_stone 		*stone;

  if (!(box = get_box(x, y)))
    return (false);
  stone->nb += nb;
  return (true);
}
