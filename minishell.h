/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:50:38 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/02 12:58:19 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"

# define SUCCESS 0
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
	char			*ori;
	char			**tab;
	struct s_comm	*next;
	struct s_comm	*last;
}				t_comm;

typedef struct	s_env
{
	char		**env;
	char		**variable;
	char		**value;
}				t_env;

struct s_env	*env;

void			ft_quit(char *msg, int outp, t_comm *comm);
void	delete_comms(t_comm *comm);

int				ft_cd(t_comm *data);
int				ft_echo(t_comm *data);
int				ft_setenv(t_comm *data);
int				ft_unsetenv(t_comm *data);
int				ft_env(t_comm *data);
int				ft_exit(t_comm *data);

char			**init_tab(int (*ft_tab[])(t_comm *data), char **tab);
void			init_env(char **tab, t_comm *comm);

void			print_prompt(t_comm *comm);
void			aff_tab(char **tab);
void			aff_list(t_comm *comm);

t_comm			*get_comms(t_comm *comm);

char			**ft_minishell_split(char *str, t_comm *comm);
void			parse_comm(t_comm *comm);

int				exec_comms(t_comm *com, char **bn, int (*fab[])(t_comm *data));

int				flags_gestion(char *flags, char **av, int x, char *list);

int				get_env(char *var);
int				is_dir(char *name);
int				ft_tablen(char **tab);
void			push_env2(void);
void			push_env(void);

int				is_bin(t_comm *comm);
int				exec_comm(char **tab);

#endif
