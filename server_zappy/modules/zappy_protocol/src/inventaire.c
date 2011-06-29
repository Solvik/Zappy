/*
** inventaire.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Tue Jun 14 17:42:10 2011 solvik blum
** Last update Tue Jun 28 17:04:06 2011 solvik blum
*/

#include <stdlib.h>

#include "itoa.h"
#include "player.h"
#include "server_zappy.h"

static void     get_len(void * data, void * arg)
{
  t_ressource	*r;

  r = (t_ressource *)data;
  *((int *)arg) += strlen(r->name) + itoa_number_size(r->n, 10) + 2; // space + ','
}

static void     cat_ressources(void * data, void * arg)
{
  t_ressource		*r;
  char **               str;
  char			*n;

  r = (t_ressource *)data;
  str = (char **)arg;
  n = itoadup(r->n);

  strcpy((*str), r->name);
  (*str) += strlen(r->name);
  *(*str) = ' ';
  ++(*str);
  strcpy((*str), n);
  (*str) += strlen(n);
  *(*str) = ',';
  ++(*str);
  free(n);
}

int		zappy_inventaire(t_fds *player, char *cmd)
{
  int		len;
  char		*str;

  (void)cmd;
  len = 0;
  foreach_arg_list(player_data->ressources, get_len, &len);
  str = malloc(len + 2);
  foreach_arg_list(player_data->ressources, cat_users, &str);
  *str = '\0';
  printf("inventaire: [[%s]]\n", str);
  send(player, str);
}
