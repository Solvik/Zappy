##
## Makefile for My IRC in myirc/lib/libitoa
## 
## Made by lepage_b
## Login   <lepage_b@epitech.net>
## 
## Started on  Thu Apr 07 22:05:40 2011 lepage_b
## Last update Sun Apr 24 23:09:03 2011 lepage_b
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
