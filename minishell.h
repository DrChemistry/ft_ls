/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:50:38 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/19 13:51:02 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL_H
# define	MINISHELL_H

#	include "./libft/libft.h"

#	define SUCCESS 0
# define FAILURE 1
# define NB_BUILT_IN 6
# define RED "\033[0;31m"
# define BOLD_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BOLD_GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BOLD_YELLOW "\033[01;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define MAGENTA "\033[0;35m"
# define BOLD_MAGENTA "\033[1;35m"
# define CYAN "\033[0;36m"
# define BOLD_CYAN "\033[1;36m"
# define RESET "\033[0m"

typedef struct	s_comm
{
	char					*ori;
	char					**tab;
	struct s_comm	*next;
	struct s_comm	*last;
}								t_comm;

typedef struct	s_env
{
	char	**env;
	char	**variable;
	char	**value;
}								t_env;

int			ft_cd(t_comm *data, t_env *env);
int			ft_echo(t_comm *data, t_env *env);
int			ft_setenv(t_comm *data, t_env *env);
int			ft_unsetenv(t_comm *data, t_env *env);
int			ft_env(t_comm *data, t_env *env);
int			ft_exit(t_comm *data, t_env *env);

int			init_env(t_env *env, char **tab);
char		**init_tab(int (*ft_tab[])(t_comm *data, t_env *env));
int			print_prompt(void);
t_comm	*parse_command(char *line);

int check_exec(t_comm *comm, t_env *env);

#endif
