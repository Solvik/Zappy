
NAME		=	client_zappy

## Directories
SRC_DIR		=	src/
CSRC_DIR	=	../common/src

INCLUDE		=	-Iinclude/			\
			-I../common/include/		\
			-I../lib/network/include	\
			-I../lib/List/include

LIB_DIR		=	../lib/

## Files Prefixes


## Sources

SRCS		=	$(SRC_DIR)main.c			\
			$(SRC_DIR)parse_cmd.c			\
			$(SRC_DIR)gere_cmd.c			\
			$(SRC_DIR)bienvenue.c			\
			$(SRC_DIR)msz.c				\
			$(SRC_DIR)smg.c				\
			$(SRC_DIR)suc.c				\
			$(SRC_DIR)sbp.c				\
			$(SRC_DIR)$(NAME).c

## Libraries
LIB		=	-L$(LIB_DIR)/network -lnet		\
			-L$(LIB_DIR)/List -llist
#			-L$(LIB_DIR)/itoa -litoa

## functions
OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc
CFLAGS		+=	-W -Wall -g3

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

