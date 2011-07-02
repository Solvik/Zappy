##
## testModule.mk for  in /Users/Lifely/Developer/project/Zappy/server_zappy
## 
## Made by Julien Di Marco
## Login   <Lifely@epitech.net>
## 
## Started on  Sat Jul  2 01:55:13 2011 Julien Di Marco
## Last update Sat Jul  2 01:55:13 2011 Julien Di Marco
##

############################################################

TOP := $(dir $(lastword $(MAKEFILE_LIST)))

INCLUDES = .				\
	   ./include/			\
	   $(SERVER)include/		\
	   $(COMMONS)include/		\
	   $(LIBRARY)List/include/	\
	   $(LIBRARY)network/include/

############################################################

TEST	= ./src/

SOURCE	= $(TEST)test.c

############################################################

INCLUDE	+= $(addprefix $(TOP),$(INCLUDES))

SOURCES	+= $(addprefix $(TOP),$(SOURCE))

############################################################