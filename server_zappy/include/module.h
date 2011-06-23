
#ifndef		MODULE_H_
# define	MODULE_H_

#  include	"network.h"
#  include	"ztypes.h"
#  include	"list.h"

typedef		struct
{
  char		*command;
  bool		(*action)(void);
}		t_mod_func;

typedef	struct	_module
{
  char *	name;
  char *	delim;
  uint		port;
  uint		antiflood;

  t_mod_func	functions;
  bool		(*handshaking)(fds, char*);
  bool		(*update)(void);
  int		(*timer)(void);

  void *	handle;
  t_list *	clients; // t_clients
}		t_module;

bool		mod_register(t_module *);
bool		mod_unregister(char *);

void		*mod_dl_load(char *);
bool		mod_load(char *);
bool		mod_unload(char *);

#endif		/* !MODULE_H_ */
