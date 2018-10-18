#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 16:55:47 by adi-rosa          #+#    #+#              #
#    Updated: 2018/07/16 19:04:43 by adi-rosa         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

MAKE	=	make -C ./libft/

RM	=	rm -f

SRC	=	main.c		\
			init.c		\
			env.c			\
			prompt.c	\
			parse_comm.c	\
			exec_comm.c	\

LIB	=	-L./libft/ -lft

OBJ	=	$(SRC:.c=.o)

INCLUDE =	-I.

NAME	=	minishell

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(LIB) $(INCLUDE)

clean:
	$(MAKE) clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
