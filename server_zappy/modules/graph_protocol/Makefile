##
## Makefile. for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/test
## 
## Made by Julien Di Marco
## Login   <Lifely@epitech.net>
## 
## Started on  Wed Jun 29 23:31:59 2011 Julien Di Marco
## Last update Thu Jun 30 12:10:09 2011 guillaume gelin
##

############################################################

NAME	= graphModule

INCLUDE	= .				\
	  ./include/			\
	  $(SERVER)include/		\
	  $(COMMONS)include/		\
	  $(LIBRARY)List/include/	\
	  $(LIBRARY)network/include/

############################################################

ROOT	= ../../../

COMMONS	= $(ROOT)common/
LIBRARY	= $(ROOT)lib/
SERVER	= $(ROOT)server_zappy/

LOCAL	= ./src/

############################################################

SOURCE	= $(LOCAL)init.c		\
	  $(LOCAL)graph_team.c		\
	  $(LOCAL)graph_time.c		\
	  $(LOCAL)graph_player.c	\
	  $(LOCAL)graph_graphic.c	\
	  $(LOCAL)graph_egg.c		\
	  $(LOCAL)graph_map.c		\
	  $(LOCAL)graph_misc.c

SOURCES	= $(SOURCE:.c=.o)

ARCHIVE	= $(LIBRARY)List/liblist.a	\
	  $(LIBRARY)network/libnet.a

############################################################

NDEBUG	?= 1
OS	= $(shell uname -s)
OS	!= uname -s
ARCHI	= $(shell uname -m)
ARCHI	!= uname -m

############################################################

MFLAG		= $(MFLAG_${OS})
MFLAG_$(OS)	= -shared -rdynamic
MFLAG_Darwin	= -bundle -flat_namespace -undefined suppress
MFLAG_darwin	= $(MFLAG_Darwin)

OFLAG		= $(OFLAG_${OS})
OFLAG_$(OS)	= -fPIC
OFLAG_Darwin	= -fno-common
OFLAG_darwin	= $(OFLAG_Darwin)

CC	= gcc

CHECK	= /u/all/astek/public/norme/norme
PRINTF	= /usr/bin/printf
CP	= cp
RM	= rm -f

CFLAGS	+= -W -Wall -Wextra		\
	   -D_${OS}_ -O3 -funroll-loops	\
	   $(addprefix -I, $(INCLUDE))

############################################################

ifeq	($(NDEBUG), 1)
 CFLAGS	+= -DNDEBUG
else
 CFLAGS	+= -ggdb
endif

############################################################

all		: $(NAME).so

$(NAME).so	: $(SOURCES)
		  @ $(PRINTF) "\nFlag used with $(CC): \033[33m$(MFLAG) $(CFLAGS)\033[m\n"
		  @ $(PRINTF) "Module name is: \033[33m$@\033[0m\n"
		  $(CC) $(MFLAG) $(CFLAGS) $(SOURCES) $(ARCHIVE) -o $@

mrpropre	: all clean

clean		:
		  $(RM) $(SOURCES)

fclean		: clean
		  $(RM) $(NAME).so

re		: fclean all

############################################################

%.o		: %.c
		  @ $(CC) $(OFLAG) $(CFLAGS) -o $@ -c $<
		  @ $(PRINTF) "\033[32m[OK]\033[0m --> $< \n"

############################################################

.PHONY		: clean fclean

.SUFFIXES	: %.c

############################################################

check		:
		  @$(CHECK) -nocheat `find . -name "*.[ch]"`

############################################################
