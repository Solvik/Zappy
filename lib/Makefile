##
## Makefile for My IRC in myirc/lib
## 
## Made by lepage_b
## Login   <lepage_b@epitech.net>
## 
## Started on  Thu Apr 07 22:05:40 2011 lepage_b
## Last update Sun Apr 24 23:09:03 2011 lepage_b
##

LIST		=	List
ITOA		=	itoa
NETW		=	network

MAKE		=	make

all		:
			@ (cd $(LIST) && $(MAKE))
			@ (cd $(ITOA) && $(MAKE))
#			@ (cd $(NETW) && $(MAKE))
clean		:
			@ (cd $(LIST) && $(MAKE) clean)
			@ (cd $(ITOA) && $(MAKE) clean)
#			@ (cd $(NETW) && $(MAKE) clean)

fclean		:
			@ (cd $(LIST) && $(MAKE) fclean)
			@ (cd $(ITOA) && $(MAKE) fclean)
#			@ (cd $(NETW) && $(MAKE) fclean)

re		:	fclean all
