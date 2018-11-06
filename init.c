/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:17:34 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/10/26 13:57:51 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	init_env(char **tab, t_comm *comm)
{
	int		x;
	char	**tmp;

	x = 0;
	if (!(env = malloc(sizeof(t_env) * 1)))
		ft_quit("minishell: erreur malloc", 2, comm);
	if (!(env->env = ft_tab_dup(tab)))
		ft_quit("minishell: erreur malloc", 2, comm);
	x = ft_tablen(tab);
	if (!(env->variable = malloc(sizeof(char *) * (x + 1)))
			|| !(env->value = malloc(sizeof(char *) * (x + 1))))
		ft_quit("minishell: erreur malloc", 2, comm);
	x = -1;
	while (tab[++x])
	{
		if (!(tmp = ft_strsplit(tab[x], '=')) ||
		!(env->variable[x] = ft_strdup(tmp[0])) ||
		!(env->value[x] = ft_strdup(tmp[1])))
			ft_quit("minishell: erreur malloc", 2, comm);
			free(tmp[0]);
			free(tmp[1]);
			free(tmp);
	}
	env->variable[x] = NULL;
	env->value[x] = NULL;
}

char	**init_tab(int (*ft_tab[])(t_comm *data), char **tab)
{
	tab[0] = "echo";
	tab[1] = "cd";
	tab[2] = "setenv";
	tab[3] = "unsetenv";
	tab[4] = "env";
	tab[5] = "exit";
	tab[6] = NULL;
	ft_tab[0] = ft_echo;
	ft_tab[1] = ft_cd;
	ft_tab[2] = ft_setenv;
	ft_tab[3] = ft_unsetenv;
	ft_tab[4] = ft_env;
	ft_tab[5] = ft_exit;
	ft_tab[6] = NULL;
	return (tab);
}
