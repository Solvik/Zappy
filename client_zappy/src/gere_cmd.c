/*
** gere_cmd.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		nothing(t_cmd *nothing)
{
  (void)nothing;
  return (1);
}

static const t_ptr ptr[] =
  {
    {"bienvenue", visu_bienvenue, 1},
    {"msz", visu_msz, 3},
    {"bct", visu_bct, 10},
    {"tna", visu_tna, 2},
    {"pnw", visu_pnw, 7},
    {"ppo", visu_ppo, 5},
    {"plv", visu_plv, 3},
    {"pin", visu_pin, 11},
    {"pbc", play_sound, 3},
    {"pic", nothing, -1},
    {"pie", nothing, 4},
    {"pfk", visu_pfk, 2},
    {"pdr", nothing, 3},
    {"pgt", nothing, 3},
    {"pdi", visu_pdi, 2},
    {"enw", visu_enw, 5},
    {"eht", nothing, 2},
    {"ebo", nothing, 2},
    {"edi", nothing, 2},
    {"sgt", nothing, 2},
    {"sgt", nothing, 2},
    {"seg", nothing, 2},
    {"smg", visu_smg, 2},
    {"suc", visu_suc, 1},
    {"sbp", visu_sbp, 1},
  };

static const int	ptr_len = sizeof(ptr) / sizeof(t_ptr);

int			gere_cmd(t_fds *pooler, t_cmd *inc_cmd, t_visu *v)
{
  int			i;

  i = -1;
  if (!inc_cmd)
    return (0);
  printf("%s\n", inc_cmd->argv[0]);
  while (++i < ptr_len)
    if ((!strcasecmp(ptr[i].cmd, inc_cmd->argv[0])))
      {
	if (inc_cmd->argc == ptr[i].argc)
	  return (ptr[i].f(pooler, inc_cmd, v));
	else
	  return (0);
      }
  return (0);
}

void			free_cmd(t_cmd *c)
{
  int			i;

  i = 0;
  while (c && c->argv && i < c->argc)
    free(c->argv[i++]);
  free(c->argv);
  if (c)
    free(c);
}
