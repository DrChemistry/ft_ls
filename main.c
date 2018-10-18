/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:49:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/19 13:49:58 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include "minishell.h"

int		is_dir(char *name)
{
	DIR *dir;

	if (!(dir = opendir(name)))
		return (FAILURE);
	closedir(dir);
	return (SUCCESS);
}

int			ft_cd(t_comm *data, t_env *env)
{
	if (is_dir(data->tab[1]) == SUCCESS)
	{
		chdir(data->tab[1]);
	}
	else if (ft_strcmp(data->tab[1], "-") == 0)
	{
		chdir(data->tab[1]);
	}
	else
	{
		ft_putstr(data->tab[1]);
		ft_putstr(": is not a directory\n");
	}
	return (SUCCESS);
}

int			ft_echo(t_comm *data, t_env *env)
{
	int x;

	x = 1;
	while (data->tab[x])
		{
			ft_putstr(data->tab[x++]);
			if (data->tab[x])
				ft_putstr(" ");
		}
	ft_putstr("\n");
	return (SUCCESS);
}

int			ft_exit(t_comm *data, t_env *env)
{
	int x;

	x = 0;
	while (env->env[x])
	{
		free(env->env[x]);
		free(env->variable[x]);
		free(env->value[x++]);
	}
	x = 0;
	while (data->tab[x])
		free(data->tab[x++]);
	if (data->ori)
		free(data->ori);
	ft_putstr("exit\n");
	return (3);
}

int push_env(t_env *env)
{
	int x;
	char *tmp;
	char *separ;

	x = 0;
	separ = "=";
	while (env->variable[x])
	{
		if (!(tmp = ft_strjoin(env->variable[x], separ))
			|| !(env->env[x] = ft_strjoin(tmp, env->value[x])))
				return (FAILURE);
		free(tmp);
		++x;
	}
	return (SUCCESS);
}

int			main(int ac, char **av, char **env)
{
	char		**line;
	char		**built_in;
	int			x;
	int			(*ft_tab[NB_BUILT_IN + 1])(t_comm *data, t_env *env);
	t_comm	*comm;
	int			back;
	t_env		envi[1];

	if (!(line = malloc(sizeof(char *) * 1)) || !(built_in = init_tab(ft_tab)))
		return (FAILURE);
	if (init_env(envi, env) == FAILURE)
		return (0);
	while (1)
	{
		if (print_prompt() == FAILURE || (get_next_line(1, line) == -1)
			|| !(comm = parse_command(line[0])))
			return (FAILURE);
		x = 0;
		while (built_in[x] && ft_strcmp(comm->tab[0], built_in[x]) != 0)
			++x;
		if (x == NB_BUILT_IN && (x = check_exec(comm, envi)) == FAILURE)
			return (FAILURE);
		if (x == NB_BUILT_IN)
			ft_putstr("Command not found\n");
		else
		{
			back = ft_tab[x](comm, envi);
			if (back == 3)
				return (0);
		}
		if (push_env(envi) == FAILURE)
			return (0);
	}
	return (0);
}
