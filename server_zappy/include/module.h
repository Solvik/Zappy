
#ifndef		MODULE_H_
# define	MODULE_H_

#  include	"ztypes.h"
#  include	"list.h"

typedef		enum
  {
    ADD,
    GET
  }		e_module_action;

typedef		struct
{
  char		*command;
  bool		(*action)(void);
}		t_mod_func;

typedef	struct	_module
{
  t_mod_func	functions;
  void *	handle;
  char *	name;
  uint		id;
  uint		port;
  uint		antiflood;
  char *	delim;
  t_list *	clients; // t_clients
}		t_module;

bool		mod_add(t_module *);
t_list *	mod_get(void);
t_module *	mod_dl_load(char *);

#endif		/* !MODULE_H_ */
