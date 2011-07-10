##
## Makefile for Zappy in ./lib/List
## 
## Made by di-mar_j
## Login   <di-mar_j@epitech.net>
## 
## Started on  Thu Jun 23 22:12:26 2011 di-mar_j
## Last update Sun Jul 10 23:15:49 2011 di-mar_j
##

NAME		=	liblist.a

SRC_DIR		=	src/

SRCS		=	$(SRC_DIR)put_in_list.c				\
			$(SRC_DIR)new_node.c				\
			$(SRC_DIR)list_from_table.c			\
			\
			$(SRC_DIR)destroy_list.c			\
			\
			$(SRC_DIR)duplicate_list.c			\
			$(SRC_DIR)duplicate_list_elem.c			\
			\
			$(SRC_DIR)dump_list.c				\
			$(SRC_DIR)foreach_list.c			\
			$(SRC_DIR)foreach_stop_list.c			\
			$(SRC_DIR)foreach_arg_list.c			\
			$(SRC_DIR)foreach_arg_stop_list.c		\
			\
			$(SRC_DIR)sub_list.c				\
			$(SRC_DIR)sub_list_arg.c			\
			\
			$(SRC_DIR)get_list_len.c			\
			\
			$(SRC_DIR)get_data_at.c				\
			$(SRC_DIR)get_data_as.c				\
			$(SRC_DIR)get_data_as_arg.c			\
			$(SRC_DIR)get_node_at.c				\
			$(SRC_DIR)get_node_as.c				\
			$(SRC_DIR)get_node_as_arg.c			\
			\
			$(SRC_DIR)del_node.c				\
			$(SRC_DIR)del_node_at.c				\
			$(SRC_DIR)del_node_as.c				\
			$(SRC_DIR)del_node_as_arg.c			\
			$(SRC_DIR)del_all_node_as.c			\
			$(SRC_DIR)del_all_node_as_arg.c			\
			\
			$(SRC_DIR)insert_data_at.c			\
			$(SRC_DIR)insert_data_after.c			\
			$(SRC_DIR)insert_data_before.c			\
			$(SRC_DIR)insert_node_after.c			\
			$(SRC_DIR)insert_node_before.c			\
			\
			$(SRC_DIR)swap_data.c				\
			$(SRC_DIR)order_list.c

AR		=	ar r

RM		=	rm -f

OBJ		=	$(SRCS:.c=.o)

CC		?=	gcc

CFLAGS		+=	-W -Wall -ansi -pedantic -ggdb #

INCLUDE		=	-Iinclude

.PHONY		: all
all		:	$(NAME)
			@ echo > /dev/null # no 'Nothing to be done' trick

$(NAME)		:	$(OBJ)
			$(AR) $(NAME) $(OBJ)
			ranlib $(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDE)
