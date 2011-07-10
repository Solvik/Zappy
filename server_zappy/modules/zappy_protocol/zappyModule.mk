##
## zappyModule.mk for  in /home/di-mar_j/git/Zappy/server_zappy/modules/zappy_protocol
## 
## Made by julien di-marco
## Login   <di-mar_j@epitech.net>
## 
## Started on  Sun Jul 10 15:55:18 2011 julien di-marco
## Last update Sun Jul 10 15:55:18 2011 julien di-marco
##

############################################################

TOP := $(dir $(lastword $(MAKEFILE_LIST)))

INCLUDE	= .				\
	  $(TOP)/include/		\
	  $(SERVER)include/		\
	  $(COMMONS)include/		\
	  $(LIBRARY)List/include/	\
	  $(LIBRARY)itoa/include/	\
	  $(LIBRARY)network/include/

############################################################

ZAPPY	= ./src/

SOURCE	= $(ZAPPY)get_module.c			\
	  $(ZAPPY)avance.c			\
	  $(ZAPPY)broadcast.c			\
	  $(ZAPPY)direction.c			\
	  $(ZAPPY)connect_nbr.c			\
	  $(ZAPPY)droite.c			\
	  $(ZAPPY)expulse.c			\
	  $(ZAPPY)fork.c			\
	  $(ZAPPY)gauche.c			\
	  $(ZAPPY)incantation.c			\
	  $(ZAPPY)inventaire.c			\
	  $(ZAPPY)pose.c			\
	  $(ZAPPY)prend.c			\
	  $(ZAPPY)voir.c			\
	  $(ZAPPY)is_stone.c			\
	  $(ZAPPY)get_ressource_id.c		\
	  $(ZAPPY)updates.c			\
	  $(ZAPPY)main.c

############################################################

INCLUDE	+= $(addprefix $(TOP),$(INCLUDES))

SOURCES	+= $(addprefix $(TOP),$(SOURCE))

############################################################