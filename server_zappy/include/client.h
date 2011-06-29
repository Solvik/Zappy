/*
** client.h for  in /home/di-mar_j/git/Zappy/server_zappy
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Tue Jun 21 16:27:48 2011 julien di-marco
** Last update Wed Jun 29 10:24:59 2011 solvik blum
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	"module.h"
# include	"flood.h"

typedef struct _client
{
  char		*command;
  t_antiflood	flood;

  t_module	*_m;
  void		*callback;
}		t_client;

#endif		/* !CLIENT_H_ */
