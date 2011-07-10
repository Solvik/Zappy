##
## network/Makefile for  in /home/di-mar_j/git/Zappy/lib
## 
## Made by julien di-marco
## Login   <di-mar_j@epitech.net>
## 
## Started on  Sun Jul 10 23:13:29 2011 julien di-marco
## Last update Sun Jul 10 23:13:29 2011 julien di-marco
##

##
## Made by	db0
## Contact	db0company@gmail.com
## Site		http://db0.fr/
##

NAME		=	libnet.a

SRC_DIR		=	sources/

POOL		?=	SELECT_

SRCS		=	$(SRC_DIR)buffer.c			\
			$(SRC_DIR)buffer_destroy.c		\
			$(SRC_DIR)buffer_utils.c		\
			$(SRC_DIR)fds.c				\
			$(SRC_DIR)fds_toolkit.c			\
			$(SRC_DIR)socket.c			\
			$(SRC_DIR)socket_get.c			\
			$(SRC_DIR)getline.c			\
			$(SRC_DIR)error.c			\
			$(SRC_DIR)inet.c			\
			$(SRC_DIR)net.c				\
			$(SRC_DIR)network.c			\
			$(SRC_DIR)pool.c			\
			$(SRC_DIR)writeline.c			\
			$(SRC_DIR)select_/select_actions.c	\
			$(SRC_DIR)select_/select_pool.c

OBJ		=	$(SRCS:.c=.o)

AR		=	ar r
RM		=	rm -f
CC		?=	gcc

CFLAGS		+=	-W -Wall -ansi -fPIC -D$(POOL)

INCLUDE		=	-Iinclude

.PHONY		:	all

all		:	$(NAME)
			@ echo > /dev/null #no 'Nothing to be done' trick

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
