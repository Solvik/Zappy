##
## Makefile for Zappy in ./lib/itoa
## 
## Made by di-mar_j
## Login   <di-mar_j@epitech.net>
## 
## Started on  Thu Jun 23 22:12:26 2011 di-mar_j
## Last update Sun Jul 10 23:15:49 2011 di-mar_j
##

# main
NAME		=	libitoa.a

# sources & objects
SRC_DIR		=	src/

SRCS		=	$(SRC_DIR)itoa_number_size.c			\
			$(SRC_DIR)itoa.c				\
			$(SRC_DIR)itoadup.c

OBJ		=	$(SRCS:.c=.o)

# include
INCLUDE		=	-Iinclude

# compilation
CC		=	gcc
CFLAGS		+=	-W -Wall -ansi -pedantic

# commands
AR		=	ar r
RM		=	rm -f

## RULES
all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(AR) $(NAME) $(OBJ)
			ranlib $(NAME)

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDE)

# clean
clean		:
			$(RM) $(OBJ)

fclean		:	$(clean)
			$(RM) $(NAME)

# re
re		:	fclean all
