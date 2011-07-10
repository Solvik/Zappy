/*
** module.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		MODULE_H_
# define	MODULE_H_

#  include	"network.h"
#  include	"ztypes.h"
#  include	"list.h"

typedef		struct
{
  char		*command;
  double	delay;
  char		relative : 1;

  bool		(*action)(fds, char*);
}		t_mod_func;

typedef	struct	_module
{
  char		*data;
  char		*name;
  char		*delim;
  uint		port;
  uint		antiflood;

  void		*handle;
  t_list 	*clients;

  bool		(*handshaking)(fds, char*);
  bool		(*disconnection)(fds);
  bool		(*update)(double);
  double	(*timer)(void);
  t_mod_func	functions[1];
}		t_module;

bool		mod_register(t_module *);
bool		mod_unregister(char *);

void		*mod_dl_load(char *);
bool		mod_load(char *);
bool		mod_unload(char *);

bool	       mod_discovery(fds, char **);

#endif		/* !MODULE_H_ */
