
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
			@(cd $(LIB_DIR) && make re)

libclean	:
			@(cd $(LIB_DIR) && make clean)

libfclean	:
			@(cd $(LIB_DIR) && make fclean)

## clean
clean		:	libclean
			@(cd $(CLIENT_DIR) && make clean)
			@(cd $(SERVER_DIR) && make clean)

fclean		:	libfclean
			@(cd $(CLIENT_DIR) && make fclean)
			@(cd $(SERVER_DIR) && make fclean)

## re
re		:	libre
			@(cd $(CLIENT_DIR) && make re)
			@(cd $(SERVER_DIR) && make re)

