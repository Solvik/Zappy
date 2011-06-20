
NAME		=	test

## Directories
SRC_DIR		=	src/

INCLUDE		=	-Iinclude/			\
			-I../../include/		\
			-I../../../common/include/	\
			-I../../../lib/List/include/	\
			-I../../../lib/network/include/

## Sources
SRCS		=	$(SRC_DIR)test.c

## functions
OBJS		=	$(SRCS:.c=.o)
RM		=	rm -f
CC		?=	gcc
CFLAGS		+=	-W -Wall

## RULES
all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -shared -rdynamic $(CFLAGS) $(OBJS) -o lib$(NAME).so

## clean
clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) lib$(NAME).so

## re
re		:	fclean all

.c.o		:
			$(CC) -fPIC -c $(CFLAGS) $< -o $(<:.c=.o) $(INCLUDE)

