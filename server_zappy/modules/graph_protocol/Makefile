
NAME		=	graphproto

## Directories
SRC_DIR		=	src/

INCLUDE		=	-Iinclude/			\
			-I../../include/		\
			-I../../../common/include/	\
			-I../../../lib/List/include/	\
			-I../../../lib/network/include/

LIB_DIR		=	../../../lib/

LIB		=	$(LIB_DIR)List/liblist.a	\
			$(LIB_DIR)network/libnet.a

## Sources
SRCS		=	$(SRC_DIR)init.c		\
			$(SRC_DIR)graph_team.c		\
			$(SRC_DIR)graph_time.c		\
			$(SRC_DIR)graph_player.c	\
			$(SRC_DIR)graph_graphic.c	\
			$(SRC_DIR)graph_egg.c		\
			$(SRC_DIR)graph_map.c

## functions
OBJS		=	$(SRCS:.c=.o)
RM		=	rm -f
CC		?=	gcc
CFLAGS		+=	-W -Wall -D_GNU_SOURCE

## RULES
all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -shared -rdynamic $(CFLAGS) $(OBJS) -o lib$(NAME).so $(LIB)

## clean
clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) lib$(NAME).so

## re
re		:	fclean all

.c.o		:
			$(CC) -fPIC -c $(CFLAGS) $< -o $(<:.c=.o) $(INCLUDE)

