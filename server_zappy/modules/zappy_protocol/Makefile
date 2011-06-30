
############################################################

NAME	= ZappyModule

INCLUDE	= .				\
	  ./include/			\
	  $(SERVER)include/		\
	  $(COMMONS)include/		\
	  $(LIBRARY)List/include/	\
	  $(LIBRARY)itoa/include/	\
	  $(LIBRARY)network/include/

############################################################

ROOT	= ../../../

COMMONS	= $(ROOT)common/
LIBRARY	= $(ROOT)lib/
SERVER	= $(ROOT)server_zappy/

LOCAL	= ./src/

############################################################

SOURCE	= $(LOCAL)get_module.c			\
	  $(LOCAL)avance.c			\
	  $(LOCAL)broadcast.c			\
	  $(LOCAL)connect_nbr.c			\
	  $(LOCAL)droite.c			\
	  $(LOCAL)expulse.c			\
	  $(LOCAL)fork.c			\
	  $(LOCAL)gauche.c			\
	  $(LOCAL)incantation.c			\
	  $(LOCAL)inventaire.c			\
	  $(LOCAL)pose.c			\
	  $(LOCAL)prend.c			\
	  $(LOCAL)voir.c			\
	  $(LOCAL)main.c

OBJS	= $(SOURCE:.c=.o)

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

$(NAME).so	: $(OBJS)
		  @ $(PRINTF) "\nFlag used with $(CC): \033[33m$(MFLAG) $(CFLAGS)\033[m\n"
		  @ $(PRINTF) "Module name is: \033[33m$@\033[m\n"
		  $(CC) $(MFLAG) $(CFLAGS) $(OBJS) $(ARCHIVE) -o $@

mrpropre	: all clean

clean		:
		  $(RM) $(OBJS)

fclean		: clean
		  $(RM) $(NAME).so

re		: fclean all

############################################################

%.o		: %.c
		  @ $(CC) $(OFLAG) $(CFLAGS) -o $@ -c $<
		  @ $(PRINTF) "\033[32m[OK]\033[m --> $< \n"

############################################################

.PHONY		: clean fclean

.SUFFIXES	: %.c

############################################################

check		:
		  @$(CHECK) -nocheat `find . -name "*.[ch]"`

############################################################
