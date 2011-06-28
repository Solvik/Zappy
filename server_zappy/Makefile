
MAKEFLAGS	+= --no-print-directory

NAME		=	server_zappy

## Directories
SRC_DIR		=	src/
COM_DIR		=	../common/
CSRC_DIR	=	$(COM_DIR)src/
LIB_DIR		=	../lib/

INCLUDE		=	-Iinclude/				\
			-I$(COM_DIR)include/			\
			-I$(LIB_DIR)network/include/		\
			-I$(LIB_DIR)List/include/		\
			-I$(LIB_DIR)itoa/include/

## Sources
SRCS		=	$(SRC_DIR)main.c			\
			$(SRC_DIR)server_zappy.c		\
			\
			$(SRC_DIR)init.c			\
			$(SRC_DIR)init_opt.c			\
			$(SRC_DIR)init_network.c		\
			$(SRC_DIR)init_map.c			\
			$(SRC_DIR)init_modules.c		\
			\
			$(SRC_DIR)mod_dl_load.c			\
			$(SRC_DIR)mod_manager.c			\
			$(SRC_DIR)mod_discovery.c		\
			\
			$(SRC_DIR)flood_manager.c		\
			\
			$(SRC_DIR)gserv_get.c			\
			$(SRC_DIR)gserv_set_map.c		\
			$(SRC_DIR)gserv_get_map.c		\
			$(SRC_DIR)gserv_setbox_addstone.c	\
			$(SRC_DIR)gserv_setbox_delstone.c	\
			$(SRC_DIR)gserv_getbox_nbstones.c	\
			$(SRC_DIR)gserv_get_network.c		\
			$(SRC_DIR)gserv_set_network.c		\
			$(SRC_DIR)gserv_add_player.c		\
			$(SRC_DIR)gserv_get_players.c		\
			$(SRC_DIR)gserv_modules.c		\
			\
			$(SRC_DIR)net_connection.c		\
			\
			$(SRC_DIR)run.c				\
			$(SRC_DIR)run_end.c			\
			\
			$(SRC_DIR)exec_actions.c		\
			$(SRC_DIR)exec_timer.c			\
			\
			$(SRC_DIR)destroy.c			\
			\
			$(SRC_DIR)dbg_show_map.c		\
			\
			$(CSRC_DIR)util_string.c		\
			$(CSRC_DIR)time.c			\
			$(CSRC_DIR)err_print_error.c		\
			$(CSRC_DIR)err_print_warning.c		\
			$(CSRC_DIR)err_syntax_error.c		#\
			modules/test/src/test.c

## Libraries
LIB		=	-L$(LIB_DIR)/List -llist -L$(LIB_DIR)/network -lnet	\
			-ldl

## functions
OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc
CFLAGS		+=	-W -Wall -Werror -rdynamic -DNOTSHARED -DBSDSOURCE

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

