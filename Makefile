##
## Makefile for makefile in /home/the.psychopath/delivery/CPool_rush2
## 
## Made by Alexandre Di.rosa
## Login   <the.psychopath@epitech.net>
## 
## Started on  Sat Oct 15 16:20:13 2016 Alexandre Di.rosa
## Last update Sun Dec  4 23:04:36 2016 Alexandre Di.rosa
##

MAKE	=	make -C ./lib/my/

RM	=	rm -f

SRC	=	my_ls.c	\
		get_the.c	\
		names_sorter.c	\
		decapitalize.c	\
		recursive.c	\
		long_format.c	\
		aff.c

LIB	=	-L./lib/my -lmy

OBJ	=	$(SRC:.c=.o)

INCLUDE =	-I.

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE)
	gcc -o $(NAME) $(OBJ) $(LIB) $(INCLUDE)


clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)

re: fclean all

 .PHONY: all clean fclean re
