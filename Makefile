##
## Makefile for  in /home/di-mar_j/git/Zappy
## 
## Made by julien di-marco
## Login   <di-mar_j@epitech.net>
## 
## Started on  Sun Jul 10 23:10:36 2011 julien di-marco
## Last update Sun Jul 10 23:10:36 2011 julien di-marco
##

CLIENT_DIR	=	client_zappy
SERVER_DIR	=	server_zappy
LIB_DIR		=	lib

## RULES

all		:	libre
			@(cd $(CLIENT_DIR) && make)
			@(cd $(SERVER_DIR) && make)
# libs
lib		:
			@(cd $(LIB_DIR) && make)

libre		:
			@(cd $(LIB_DIR) && make)

libclean	:
			@(cd $(LIB_DIR) && make clean)

libfclean	:
			@(cd $(LIB_DIR) && make fclean)

## clean
clean		:
			@(cd $(CLIENT_DIR) && make clean)
			@(cd $(SERVER_DIR) && make clean)

fclean		:
			@(cd $(CLIENT_DIR) && make fclean)
			@(cd $(SERVER_DIR) && make fclean)

## re
re		:	libre
			@(cd $(CLIENT_DIR) && make re)
			@(cd $(SERVER_DIR) && make re)

