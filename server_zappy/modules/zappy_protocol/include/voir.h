/*
** voir.h for Zappy in ./server_zappy/modules/zappy_protocol/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		VOIR_H_
# define	VOIR_H_

#include	"stone.h"
#include	"player.h"
#include	"zappy_protocol.h"

typedef enum	translation_
  {
    VERTICAL,
    HORIZONTAL,
    NORMAL
  }		e_translation;

typedef struct	s_enum_to_ressource
{
  e_stone	stone;
  char		*str;
}		t_enum_to_ressource;

typedef struct voir_algo
{
  e_direction	d;
  e_translation	t;
}		t_voir_algo;

static t_enum_to_ressource     gl_ressource_name[] =
  {
    {LINEMATE, " linemate"},
    {DERAUMERE, " deraumere"},
    {SIBUR, " sibur"},
    {MENDIANE, " mendiane"},
    {PHIRAS, " phiras"},
    {THYSTAME, " thystame"}
  };

#define SIZE_STONE (sizeof(gl_ressource_name) / sizeof(t_enum_to_ressource))
#define EDIRSIZE (sizeof(algo) / sizeof(t_voir_algo))

static const int size_stone = SIZE_STONE;

void		stone(void *elem, void *arg);

#endif		/* !VOIR_H_ */
