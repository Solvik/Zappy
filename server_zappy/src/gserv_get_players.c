/*
** gserv_get_players.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:28 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:28 2011 Julien Di Marco
*/

#include		<stdlib.h>
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

t_list			*get_players(uint x, uint y)
{
  t_box 		*box;

  if (!(box = get_box(x, y)))
    return (false);
  return (box->players);
}
