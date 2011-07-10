/*
** gserv_get_eggs.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"tserver.h"

extern t_server *gserv;

t_list		*get_eggs(void)
{
  return (gserv->egg);
}
