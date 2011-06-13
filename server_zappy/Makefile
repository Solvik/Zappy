
NAME		=	server_zappy

## Directories
SRC_DIR		=	src/
CSRC_DIR	=	../common/src

INCLUDE		=	-Iinclude/ -I../common/include/ -I../lib/
LIB_DIR		=	../lib/

## Sources
SRCS		=	$(SRC_DIR)main.c			\
			$(SRC_DIR)$(NAME).c			\
			\
			$(SRC_DIR)init.c			\
			$(SRC_DIR)init_opt.c			\
			$(SRC_DIR)init_network.c		\
			$(SRC_DIR)init_map.c			\
			\
			$(SRC_DIR)destroy.c

## Libraries
LIB		=	-L$(LIB_DIR)/List -llist

## functions
OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc
CFLAGS		+=	-W -Wall -g

## RULES

all		:	$(NAME)

$(NAME)		:	lib $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

# libs
lib		:
			@(cd $(LIB_DIR) && make)

libre		:
			@(cd $(LIB_DIR) && make re)

libclean	:
			@(cd $(LIB_DIR) && make clean)

libfclean	:
			@(cd $(LIB_DIR) && make fclean)

## clean
clean		:	libclean
			$(RM) $(OBJS)

fclean		:	libfclean clean
			$(RM) $(NAME)

## re
re		:	fclean libre all

.c.o		:
			$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) $(INCLUDE)

