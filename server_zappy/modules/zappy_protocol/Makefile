
NAME		=	zappy_protocol

## Directories
SRC_DIR		=	src/

LIB_DIR		=	../../../lib/

INCLUDE		=	-Iinclude/			\
			-I../../include/		\
			-I../../../common/include/	\
			-I../../../lib/List/include/	\
			-I../../../lib/itoa/include/	\
			-I../../../lib/network/include/

LIB		=	$(LIB_DIR)List/liblist.a	\
			$(LIB_DIR)network/libnet.a

## Sources
SRCS		=	$(SRC_DIR)avance.c			\
			$(SRC_DIR)broadcast_texte.c		\
			$(SRC_DIR)connect_nbr.c			\
			$(SRC_DIR)droite.c			\
			$(SRC_DIR)expulse.c			\
			$(SRC_DIR)fork.c			\
			$(SRC_DIR)gauche.c			\
			$(SRC_DIR)incantation.c			\
			$(SRC_DIR)inventaire.c			\
			$(SRC_DIR)pose_object.c			\
			$(SRC_DIR)prend_object.c		\
			$(SRC_DIR)voir.c			\
			$(SRC_DIR)main.c			\


## functions
OBJS		=	$(SRCS:.c=.o)
RM		=	rm -f
CC		?=	gcc
CFLAGS		+=	-W -Wall

## RULES
all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -shared -rdynamic $(CFLAGS) $(OBJS) $(LIB) -o lib$(NAME).so

## clean
clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) lib$(NAME).so

## re
re		:	fclean all

.c.o		:
			$(CC) -fPIC -c $(CFLAGS) $< -o $(<:.c=.o) $(INCLUDE)

