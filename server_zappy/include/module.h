
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
  char *	name;
  char *	delim;
  uint		port;
  uint		antiflood;

  void *	handle;
  t_list *	clients; // t_clients

  bool		(*handshaking)(fds, char*);
  bool		(*update)(void);
  int		(*timer)(void);
  t_mod_func	functions[1];
}		t_module;

bool		mod_register(t_module *);
bool		mod_unregister(char *);

void		*mod_dl_load(char *);
bool		mod_load(char *);
bool		mod_unload(char *);

bool	       mod_discovery(fds client, char **cmd);

#endif		/* !MODULE_H_ */
