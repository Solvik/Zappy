/*
** gere_cmd.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 00:40:09 2011 solvik blum
** Last update Wed Jul  6 01:13:13 2011 solvik blum
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		lol(t_cmd *lol)
{
  (void)lol;
  printf("rofl\n");
  return (1);
}

static const t_ptr ptr[] =
  {
    {"bienvenue", visu_bienvenue, 1},
    {"msz", visu_msz, 3},
    {"bct", lol, 10},
    {"tna", lol, 2},
    {"pnw", lol, 7},
    {"ppo", lol, 5},
    {"plv", lol, 3},
    {"pin", lol, 11},
    {"pex", lol, 2},
    {"pbc", lol, 3},
    {"pic", lol, -1},
    {"pie", lol, 4},
    {"pfk", lol, 2},
    {"pdr", lol, 3},
    {"pgt", lol, 3},
    {"pdi", lol, 2},
    {"enw", lol, 5},
    {"eht", lol, 2},
    {"ebo", lol, 2},
    {"edi", lol, 2},
    {"sgt", lol, 2},
    {"sgt", lol, 2},
    {"seg", lol, 2},
    {"smg", lol, 2},
    {"suc", lol, 2},
    {"sbp", lol, 1},
  };

static const int	ptr_len = sizeof(ptr) / sizeof(t_ptr);

int			gere_cmd(t_fds *pooler, t_cmd *inc_cmd)
{
  int			i;

  i = 0;
  printf("Command find: %s %d\n", inc_cmd->argv[0], inc_cmd->argc);
  while (i < ptr_len)
    {
      if ((!strcasecmp(ptr[i].cmd, inc_cmd->argv[0])))
	{
	  if (inc_cmd->argc == ptr[i].argc || inc_cmd->argc == -1)
	    return (ptr[i].f(pooler, inc_cmd));
	  else
	    return (0);
	}
      i++;
    }
  return (0);
}

void			free_cmd(t_cmd *c)
{
  int			i;

  i = 0;
  while (c->argv && c->argv[i])
    free(c->argv[i++]);
  free(c->argv);
  free(c);
}
