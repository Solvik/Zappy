
#include	<unistd.h>
#include	<signal.h>

#include	"map.h"
#include	"zopt.h"
#include	"init.h"
#include	"tserver.h"
#include	"server_zappy.h"

t_server	*gserv;

void		sigint_handler(int _)
{
  (void)_;
  gserv->run = false;
  write(STDOUT_FILENO, "\b\b", 2);
}

bool		init(int opt_size, char ** opt)
{
  t_zopt	optab;

  gserv_const(true);
  if ((signal(SIGINT, sigint_handler) == SIG_ERR) ||
      !init_opt(opt_size, opt, &optab) ||
      !init_map(&optab) ||
      !init_network(&optab) ||
      !init_modules(&optab))
    return (false);
  return ((gserv->run = true));
}
