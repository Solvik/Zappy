
#include	"game.h"
#include	"init.h"
#include	"destroy.h"
#include	"server_zappy.h"

t_game *	game;

bool		server_zappy(int opt_size, char ** opt)
{
  t_game	s;

  game = &s;
  init(opt_size, opt);
  run();
  destroy(&s);
  return (true);
}
