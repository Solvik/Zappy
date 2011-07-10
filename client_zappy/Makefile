##
## client_zappy/Makefile for  in /home/di-mar_j/git/Zappy/lib
## 
## Made by julien di-marco
## Login   <di-mar_j@epitech.net>
## 
## Started on  Sun Jul 10 23:13:42 2011 julien di-marco
## Last update Sun Jul 10 23:13:42 2011 julien di-marco
##

NAME		=	client_zappy

## Directories
SRC_DIR		=	src/
CSRC_DIR	=	../common/src/

INCLUDE		=	-Iinclude/			\
			-I../common/include/		\
			-I../lib/network/include	\
			-I../lib/List/include

LIB_DIR		=	../lib/


## Sources

SRCS		=	$(SRC_DIR)main.c			\
			$(SRC_DIR)parse_cmd.c			\
			$(SRC_DIR)gere_cmd.c			\
			$(SRC_DIR)handle.c			\
			$(SRC_DIR)get_player_by_id.c		\
			$(SRC_DIR)bienvenue.c			\
			$(SRC_DIR)msz.c				\
			$(SRC_DIR)smg.c				\
			$(SRC_DIR)suc.c				\
			$(SRC_DIR)sbp.c				\
			$(SRC_DIR)tna.c				\
			$(SRC_DIR)bct.c				\
			$(SRC_DIR)pnw.c				\
			$(SRC_DIR)ppo.c				\
			$(SRC_DIR)plv.c				\
			$(SRC_DIR)pin.c				\
			$(SRC_DIR)pdi.c				\
			$(SRC_DIR)pfk.c				\
			$(SRC_DIR)enw.c				\
			$(SRC_DIR)sound.c			\
			$(SRC_DIR)draw.c			\
			$(SRC_DIR)get_info.c			\
			$(SRC_DIR)refresh.c			\
			$(CSRC_DIR)time.c			\
			$(SRC_DIR)$(NAME).c

## Libraries
LIB		=	-L$(LIB_DIR)/network -lnet		\
			-L$(LIB_DIR)/List -llist		\
			-L$(LIB_DIR)/itoa -litoa		\
			-Wl,-rpath -Wl,$(LIB_DIR)		\
			-L$(LIB_DIR) -lfmodex			\
			 `sdl-config --libs`			\
			-lSDL_ttf				\

## functions
OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc
CFLAGS		+=	-W -Wall -Wextra `sdl-config --cflags`

## RULES

all		:	lib $(NAME)

$(NAME)		:	$(OBJS)
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
clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

## re
re		:	fclean all

.c.o		:
			$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) $(INCLUDE)

