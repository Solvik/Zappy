##
## Makefile for Zappy in ./lib
## 
## Made by di-mar_j
## Login   <di-mar_j@epitech.net>
## 
## Started on  Thu Jun 23 22:12:26 2011 di-mar_j
## Last update Sun Jul 10 23:15:49 2011 di-mar_j
##

LIST		=	List
ITOA		=	itoa
NETW		=	network

MAKE		=	make

all		:
			@ (cd $(LIST) && $(MAKE))
			@ (cd $(ITOA) && $(MAKE))
			@ (cd $(NETW) && $(MAKE))
clean		:
			@ (cd $(LIST) && $(MAKE) clean)
			@ (cd $(ITOA) && $(MAKE) clean)
			@ (cd $(NETW) && $(MAKE) clean)

fclean		:
			@ (cd $(LIST) && $(MAKE) fclean)
			@ (cd $(ITOA) && $(MAKE) fclean)
			@ (cd $(NETW) && $(MAKE) fclean)

re		:	fclean all
