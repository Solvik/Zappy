##
## Makefile. for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/test
##
## Made by Julien Di Marco
## Login   <Lifely@epitech.net>
##
## Started on  Wed Jun 29 23:31:59 2011 Julien Di Marco
## Lastedi on  Wed Jun 29 23:31:59 2011 Julien Di Marco
##

############################################################

NAME	= server_zappy

INCLUDE	= .				\
	  ./include/			\
	  $(SERVER)include/		\
	  $(COMMONS)include/		\
	  $(LIBRARY)List/include/	\
	  $(LIBRARY)network/include/

MODULES	+=

############################################################

ROOT	= ../

COMMONS	= $(ROOT)common/
LIBRARY	= $(ROOT)lib/
SERVER	= $(ROOT)server_zappy/

LOCAL	= ./src/
COMMON	= $(COMMONS)src/

############################################################

SOURCES	= $(LOCAL)main.c			\
	  $(LOCAL)server_zappy.c		\
	  \
	  $(LOCAL)init.c			\
	  $(LOCAL)init_opt.c			\
	  $(LOCAL)init_random.c			\
	  $(LOCAL)init_network.c		\
	  $(LOCAL)init_map.c			\
	  $(LOCAL)init_names.c			\
	  $(LOCAL)init_modules.c		\
	  \
	  $(LOCAL)mod_dl_load.c			\
	  $(LOCAL)mod_manager.c			\
	  $(LOCAL)mod_discovery.c		\
	  \
	  $(LOCAL)flood_manager.c		\
	  \
	  $(LOCAL)scheduler_internal.c		\
	  $(LOCAL)scheduler_relative.c		\
	  \
	  $(LOCAL)callback_user.c		\
	  $(LOCAL)callback_internal.c		\
	  \
	  $(LOCAL)event_user.c			\
	  $(LOCAL)event_internal.c		\
	  \
	  $(LOCAL)new_player.c			\
	  \
	  $(LOCAL)map_random_inventory.c	\
	  $(LOCAL)map_random_stone.c		\
	  $(LOCAL)map_random_food.c		\
	  \
	  $(LOCAL)gserv_get.c			\
	  $(LOCAL)gserv_set_info.c		\
	  $(LOCAL)gserv_set_map.c		\
	  $(LOCAL)gserv_set_box_addstone.c	\
	  $(LOCAL)gserv_set_box_delstone.c	\
	  $(LOCAL)gserv_set_box_addfood.c	\
	  $(LOCAL)gserv_set_box_delfood.c	\
	  $(LOCAL)gserv_set_box_addplayer.c	\
	  $(LOCAL)gserv_set_box_delplayer.c	\
	  $(LOCAL)gserv_set_box_addegg.c	\
	  $(LOCAL)gserv_set_box_delegg.c	\
	  $(LOCAL)gserv_set_player_addstone.c	\
	  $(LOCAL)gserv_set_player_delstone.c	\
	  $(LOCAL)gserv_set_player_addfood.c	\
	  $(LOCAL)gserv_set_player_delfood.c	\
	  \
	  $(LOCAL)gserv_get_map.c		\
	  $(LOCAL)gserv_get_module_by_name.c	\
	  $(LOCAL)gserv_get_box_nbfood.c	\
	  $(LOCAL)gserv_get_box_nbstones.c	\
	  $(LOCAL)gserv_get_box_nbstones_by_player.c	\
	  $(LOCAL)gserv_get_box_players.c	\
	  $(LOCAL)gserv_get_info.c		\
	  $(LOCAL)gserv_get_player_by_id.c	\
	  $(LOCAL)gserv_get_box_players_by_level.c	\
	  $(LOCAL)gserv_get_player_info.c	\
	  $(LOCAL)gserv_get_player_nbstones.c	\
	  $(LOCAL)gserv_get_eggs.c		\
	  $(LOCAL)gserv_get_teams.c		\
	  $(LOCAL)gserv_get_team_of_player.c	\
	  $(LOCAL)gserv_get_team_by_name.c	\
	  $(LOCAL)gserv_available_names.c	\
	  $(LOCAL)gserv_modules.c		\
	  $(LOCAL)gserv_event.c			\
	  $(LOCAL)gserv_event_handler.c		\
	  \
	  $(LOCAL)net_connection.c		\
	  \
	  $(LOCAL)run.c				\
	  $(LOCAL)run_end.c			\
	  \
	  $(LOCAL)exec_updates.c		\
	  $(LOCAL)exec_actions.c		\
	  $(LOCAL)exec_event.c			\
	  $(LOCAL)exec_timer.c			\
	  \
	  $(LOCAL)destroy.c			\
	  $(LOCAL)destroy_player.c		\
	  \
	  $(LOCAL)dbg_show_map.c		\
	  $(LOCAL)err_usage.c			\
	  \
	  $(COMMON)util_string.c		\
	  $(COMMON)time.c			\
	  $(COMMON)err_print_error.c		\
	  $(COMMON)err_print_warning.c		\
	  $(COMMON)err_syntax_error.c		\
	  $(COMMON)err_syntax_debug.c		\
	  \
	  $(LOCAL)napi_functions.c

include	$(MODULES)

############################################################

SOURCES := $(patsubst $(realpath $(ROOT))/%,$(ROOT)%, $(sort $(realpath $(SOURCES))))
INCLUDE := $(patsubst $(realpath $(ROOT))/%,$(ROOT)%, $(sort $(realpath $(INCLUDE))))

############################################################

OBJECTS	= $(SOURCES:.c=.o)

LIBRARIES = $(LIBRARY)List			\
	    $(LIBRARY)network

############################################################

NDEBUG	?= 1
OS	= $(shell uname -s)
OS	!= uname -s
ARCHI	= $(shell uname -m)
ARCHI	!= uname -m

############################################################

CC	= gcc

CHECK	= /u/all/astek/public/norme/norme
PRINTF	?= /usr/bin/printf
CP	= cp
RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -Werror -rdynamic	\
	   -DNOTSHARED -DBSDSOURCE		\
	   -D_${OS}_ -O3 -funroll-loops		\
	   $(addprefix -I, $(INCLUDE))

LDFLAGS	+= $(addprefix -L, $(LIBRARIES))\
	   -llist -lnet -ldl -lm

############################################################

ifeq	($(NDEBUG), 1)
 CFLAGS	+= -DNDEBUG
else
 CFLAGS	+= -ggdb
endif

############################################################

.PHONY		: clean fclean

.SUFFIXES	: %.c

############################################################

all		: libraries $(NAME)

$(NAME)		: $(OBJECTS)
		  @ $(PRINTF) "\n Flag used with $(CC): \033[33m$(CFLAGS)\033[m\n"
		  @ $(PRINTF) " Liraries linked: \033[33m$(LDFLAGS)\033[m\n"
		  @ $(PRINTF) "Binary name is: \033[33m$@\033[m\n"
		  $(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

mrpropre	: all clean

clean		:
		  $(RM) $(OBJECTS)

fclean		: clean
		  $(RM) $(NAME)

re		: fclean all

############################################################

%.o		: %.c
		  @ $(CC) $(OFLAG) $(CFLAGS) -o $@ -c $<
#		  @ $(if $$?, echo "hello", echo "hella")
		  @ $(PRINTF) "\033[32m[OK]\033[m --> $< \n"

libraries	: $(LIBRARIES)
		  @for library in $^;do make --directory $$library ;done

############################################################

check		:
		  @$(CHECK) -nocheat `find . -name "*.[ch]"`

############################################################
