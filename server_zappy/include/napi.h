/*
** napi.h for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 29 02:09:54 2011 julien di-marco
** Last update Wed Jun 29 02:09:54 2011 julien di-marco
*/

#ifndef		NAPI_H_
# define	NAPI_H_

# include	"scheduler.h"
# include	"callback.h"
# include	"module.h"
# include	"net.h"

# include	"map.h"
# include	"tserver.h"

bool		add_command(t_mod_func *, char *, void *);

#endif		/* !NAPI_H_ */
