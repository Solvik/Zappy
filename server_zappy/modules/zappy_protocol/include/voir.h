/*
** voir.h for  in /home/solvik/tek2/proj/Zappy/server_zappy/modules/zappy_protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jun 29 16:18:48 2011 solvik blum
** Last update Wed Jun 29 16:56:43 2011 solvik blum
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

typedef struct	s_zappy_voir
{
  e_direction	dir;
  void		(*f)();
}		t_zappy_voir;

#endif		/* !VOIR_H_ */
