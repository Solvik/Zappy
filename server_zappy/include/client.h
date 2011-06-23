/*
** client.h for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Jun 21 16:27:48 2011 julien di-marco
** Last update Tue Jun 21 16:27:48 2011 julien di-marco
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

#include	"module.h"

typedef struct	_antiflood
{
  char		**array;
  long		read;
  long		write;
  int		size;
}		t_antiflood;

typedef struct _client
{
  char		*command;
  t_antiflood	flood;

  t_module	*_m;
  void		*callback;
}		t_client;

#endif		/* !CLIENT_H_ */
