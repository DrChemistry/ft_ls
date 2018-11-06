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

ECHO	= echo

SRC	=	main.c							\
			exit.c							\
			init.c							\
			ft_cd.c							\
			ft_echo.c						\
			env.c								\
			print.c							\
			commands_controls.c	\
			parse_comm.c				\
			exec_comm.c					\
			flags_handle.c			\
			tools.c							\
			path_exec.c					\

LIB	=	-L./libft/ -lft

OBJ	=	$(SRC:.c=.o)

INCLUDE =	-I.

NAME	=	minishell

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(LIB) $(INCLUDE)
	@$(ECHO) "\033[33;32m=== Compilation\t\t\tDONE ===\033[0m"

clean:
	@$(MAKE) clean
	@$(RM) $(OBJ)
	@$(ECHO) "\033[33;31m=== Object\t\t\tDELETED===\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean
	@$(ECHO) "\033[33;31m=== Binary\t\t\tDELETED===\033[0m"

re: fclean all

.PHONY: all clean fclean re
