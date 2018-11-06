/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:28:42 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/02 12:55:12 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void	change_pwd(char *dir)
{
	int	x;
	int	y;

	x = get_env("PWD");
	y = get_env("OLDPWD");
	if (y != -1 && x != -1)
	{
		free(env->value[y]);
		env->value[y] = env->value[x];
	}
	if (x != -1)
	{
		if (y == -1)
			free(env->value[x]);
		if (!(env->value[x] = ft_strdup(dir)))
			ft_quit("minishell: erreur malloc", 2, NULL);
	}
}

int		change_dir(char *dir)
{
	if (is_dir(dir) == SUCCESS)
	{
		if (chdir(dir) == -1)
		{
			ft_putendl_fd("chdir failed", 2);
			return (FAILURE);
		}
		change_pwd(dir);
		return (SUCCESS);
	}
	ft_putendl_fd("No such directory", 2);
	return (FAILURE);
}

int		cd_env(char *str)
{
	int x;

	if ((x = get_env(str)) == -1 || !env->value[x])
	{
		ft_putstr_fd("No ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(" environnematal variable", 2);
		return (FAILURE);
	}
	return (change_dir(env->value[x]));
}

int		ft_cd(t_comm *data)
{
	int		x;
	char	*tmp;
	char	*lol;

	lol = "/";
	x = ft_tablen(data->tab);
	if (x == 1)
		return (cd_env("HOME"));
	else if (x == 2)
	{
		if (ft_strcmp(data->tab[1], "-") == 0)
			return (cd_env("OLDPWD"));
		else
		{
			if (data->tab[1][ft_strlen(data->tab[1]) - 1] != '/')
			{
				if (!(tmp = ft_strjoin(data->tab[1], lol)))
					ft_quit("minishell: erreur malloc", 2, NULL);
				free(data->tab[1]);
				data->tab[1] = tmp;
			}
			return (change_dir(data->tab[1]));
		}
	}
	return (FAILURE);
}
