/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:29:03 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/01 16:31:12 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	set_env(char *str, int pos, t_comm *comm)
{
	int		x;
	char	**tab;

	x = 0;
	while (env->variable[x] && ft_strncmp(env->variable[x], str, pos) != 0)
		++x;
	if (env->variable[x])
	{
		free(env->value[x]);
		env->value[x] = ft_strdup(str + pos + 1);
	}
	else
	{
		if (!(tab = malloc(sizeof(char *) * (ft_tablen(env->env) + 2))))
			ft_quit("minishell: erreur malloc", 2, comm);
		x = -1;
		while (env->env[++x])
			tab[x] = env->env[x];
		if (!(tab[x++] = ft_strdup(str)))
			ft_quit("minishell: erreur malloc", 2, comm);
		tab[x] = NULL;
		free(env->env);
		env->env = tab;
		push_env2();
	}
}

int		ft_setenv(t_comm *data)
{
	int	x;

	x = ft_tablen(data->tab);
	if (x == 2)
	{
		if (data->tab[1][ft_findchar(data->tab[1], '=')] != '=')
		{
			ft_putendl_fd("Usage: setenv \"NAME=VALUE\"", 2);
			return (FAILURE);
		}
		set_env(data->tab[1], ft_findchar(data->tab[1], '='), data);
	}
	else if (x == 1)
		return (ft_env(data));
	else
	{
		ft_putendl_fd("too many arguements to command setenv", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

int		ft_unsetenv(t_comm *data)
{
	int	x;

	x = ft_tablen(data->tab);
	if (x == 2)
	{
		if ((x = get_env(data->tab[1])) == -1)
			return (SUCCESS);
		free(env->env[x]);
		while (env->env[x + 1])
		{
			env->env[x] = env->env[x + 1];
			++x;
		}
		env->env[x] = NULL;
		push_env2();
	}
	else
	{
		ft_putendl_fd("Usage: unsetenv \"ENV_VARIABLE\"", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

int		ft_env(t_comm *data)
{
	int	x;

	x = 0;
	while (env->env[x])
		ft_putendl(env->env[x++]);
	return (SUCCESS);
}
