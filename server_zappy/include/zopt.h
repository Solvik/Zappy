
#ifndef		ZAPPY_OPT
# define	ZAPPY_OPT

typedef		struct
{
  int		port;
  int		width;
  int		height;
  int		nb_client;
  int		delay;
  int		time;
}		t_zopt;

/*
** time should be a great option to change the time referential
** wich by default is 1 second aka 1 000 000 usec.
**
*/

#endif		/* !ZAPPY_OPT */
