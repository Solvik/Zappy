/*
** module.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:08:05 2011 Julien Di Marco
** Last update Thu Jun 30 05:08:05 2011 Julien Di Marco
*/

#ifndef		MODULE_H_
# define	MODULE_H_

#  include	"network.h"
#  include	"ztypes.h"
#  include	"list.h"

typedef		struct
{
  char		*command;
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
  bool		(*update)(double);
  int		(*timer)(void);
  t_mod_func	functions[1];
}		t_module;

bool		mod_register(t_module *);
bool		mod_unregister(char *);

void		*mod_dl_load(char *);
bool		mod_load(char *);
bool		mod_unload(char *);

bool	       mod_discovery(fds, char **);

#endif		/* !MODULE_H_ */
