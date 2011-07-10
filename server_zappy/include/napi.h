/*
** napi.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
