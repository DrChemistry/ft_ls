/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:41:00 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/02 13:02:19 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include "minishell.h"

int		get_env(char *var)
{
	int	x;

	x = 0;
	while (env->variable[x] && ft_strcmp(env->variable[x], var) != 0)
		++x;
	return (env->variable[x] == NULL ? -1 : x);
}

int		is_dir(char *name)
{
	DIR	*dir;

	if (!(dir = opendir(name)))
		return (FAILURE);
	closedir(dir);
	return (SUCCESS);
}

int		ft_tablen(char **tab)
{
	int	x;

	x = 0;
	while (tab && tab[x])
		++x;
	return (x);
}

void	push_env2(void)
{
	int		x;
	char	**tmp;

	x = 0;
	while (env->variable[x])
	{
		free(env->variable[x]);
		free(env->value[x++]);
	}
	free(env->variable);
	free(env->value);
	x = ft_tablen(env->env);
	if (!(env->variable = malloc(sizeof(char *) * (x + 1)))
			|| !(env->value = malloc(sizeof(char *) * (x + 1))))
		ft_quit("minishell: erreur malloc", 2, NULL);
	x = 0;
	while (env->env[x])
	{
		if (!(tmp = ft_strsplit(env->env[x], '=')))
			ft_quit("minishell: erreur malloc", 2, NULL);
		env->variable[x] = tmp[0];
		env->value[x++] = tmp[1];
	}
	env->variable[x] = NULL;
	env->value[x] = NULL;
}

void	push_env(void)
{
	int		x;
	char	*tmp;
	char	*separ;

	x = 0;
	separ = "=";
	while (env->variable[x])
	{
		free(env->env[x]);
		if (!(tmp = ft_strjoin(env->variable[x], separ))
				|| !(env->env[x] = ft_strjoin(tmp, env->value[x])))
			ft_quit("minishell: erreur malloc", 2, NULL);
		free(tmp);
		++x;
	}
}
