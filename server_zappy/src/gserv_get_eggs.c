/*
** gserv_get_eggs.c for zappy in /home/gelin_g/Zappy/server_zappy/src
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Sun Jul 10 02:02:35 2011 guillaume gelin
** Last update Sun Jul 10 02:05:46 2011 guillaume gelin
*/

#include	"tserver.h"

extern t_server *gserv;

t_list		*get_eggs(void)
{
  return (gserv->egg);
}
