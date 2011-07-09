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

#  include	<stdbool.h>
#  include	"ztypes.h"
#  include	"error.h"
#  include	"conf.h"

# include	"net.h"
# include	"module.h"

# include	"map.h"
# include	"egg.h"
# include	"stone.h"
# include	"player.h"
# include	"tserver.h"

# include	"scheduler.h"
# include	"callback.h"
# include	"event.h"

#define X(a)	(((a < 0) ? (int)get_map_width() : 0) + \
		 (a % ((int)get_map_width() - ((a < 0) ? -1 : 0))))

#define Y(a)	(((a < 0) ? (int)get_map_height() : 0) + \
		 (a % ((int)get_map_height() - ((a < 0) ? -1 : 0))))


#define SIZEMODULE(f)	((sizeof(t_module) + (sizeof(t_mod_func) * f)))

bool		command_add(t_mod_func *, char *, void *);
bool		command_relative(t_mod_func*, char*, void*, double);
bool		command_universel(t_mod_func*, char*, void*, double);

#endif		/* !NAPI_H_ */
