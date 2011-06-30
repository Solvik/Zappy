/*
** voir.h for  in /home/solvik/tek2/proj/Zappy/server_zappy/modules/zappy_protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jun 29 16:18:48 2011 solvik blum
** Last update Thu Jun 30 09:52:36 2011 solvik blum
*/

#ifndef		VOIR_H_
# define	VOIR_H_

#include	"stone.h"
#include	"player.h"
#include	"zappy_protocol.h"

typedef struct	s_enum_to_ressource
{
  e_stone	stone;
  char		*str;
}		t_enum_to_ressource;

static t_enum_to_ressource     gl_ressource_name[] =
  {
    {LINEMATE,	" linemate"},
    {DERAUMERE, " deraumere"},
    {SIBUR,	" sibur"},
    {MENDIANE,	" mendiane"},
    {PHIRAS,	" phiras"},
    {THYSTAME,	" thystame"}
  };

static const int size_stone = sizeof(gl_ressource_name) / sizeof(t_enum_to_ressource);

typedef struct	s_zappy_voir
{
  e_direction	dir;
  void		(*f)();
}		t_zappy_voir;

#endif		/* !VOIR_H_ */
