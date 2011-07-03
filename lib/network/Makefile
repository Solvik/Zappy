##
## Made by	db0
## Contact	db0company@gmail.com
## Site		http://db0.fr/
##

NAME		= libnet.a

SRC_DIR		= sources/

SRCS		= $(SRC_DIR)buffer.c		\
		  $(SRC_DIR)buffer_destroy.c	\
		  $(SRC_DIR)buffer_utils.c	\
		  $(SRC_DIR)fds.c		\
		  $(SRC_DIR)getline.c		\
		  $(SRC_DIR)inet.c		\
		  $(SRC_DIR)net.c		\
		  $(SRC_DIR)network.c		\
		  $(SRC_DIR)pool.c		\
		  $(SRC_DIR)writeline.c

OBJ		= $(SRCS:.c=.o)

AR		= ar r
RM		= rm -f
CC		?= gcc

CFLAGS		+= -W -Wall -ansi -ggdb #

INCLUDE		= -Iinclude

.PHONY		: all
all		: $(NAME)
		 @ echo > /dev/null #no 'Nothing to be done' trick

$(NAME)		: $(OBJ)
		  $(AR) $(NAME) $(OBJ)
		  ranlib $(NAME)

clean		:
		  $(RM) $(OBJ)

fclean		: clean
		  $(RM) $(NAME)

re		: fclean all

.c.o		:
		  $(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDE)
