
#ifndef		STONE_H_
# define	STONE_H_

typedef		enum
  {
    LINEMATE,
    DERAUMETRE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }		e_stone;

typedef		struct
{
  e_stone	type;
  uint		nb;
}		t_stone;

#endif		/* !STONE_H_ */
