
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
			$(SRC_DIR)$(NAME).c			\
			\
			$(SRC_DIR)init.c			\
			$(SRC_DIR)init_opt.c			\
			$(SRC_DIR)init_network.c		\
			$(SRC_DIR)init_map.c			\
			$(SRC_DIR)init_modules.c		\
			\
			$(SRC_DIR)mod_dl_load.c			\
			$(SRC_DIR)mod_manager.c			\
			\
			$(SRC_DIR)gserv_set_map.c		\
			$(SRC_DIR)gserv_get_map.c		\
			$(SRC_DIR)gserv_modules.c		\
			\
			$(SRC_DIR)net_wait_clients.c		\
			\
			$(SRC_DIR)run.c				\
			$(SRC_DIR)run_end.c			\
			\
			$(SRC_DIR)destroy.c			\
			\
			$(SRC_DIR)dbg_show_map.c		\
			\
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
CFLAGS		+=	-W -Wall -Werror -DNOTSHARED

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

