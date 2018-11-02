/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:50:27 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/02 13:14:35 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "minishell.h"

int	s_d2(char *bins, struct dirent *dirent, t_comm *comm)
{
	char		*lol;
	char		*tmp;
	char		*tmp2;
	struct stat	sta;

	lol = "/";
	if (!(tmp = ft_strjoin(bins, lol)))
		ft_quit("minishell: erreur malloc", 2, comm);
	if (!(tmp2 = ft_strjoin(tmp, dirent->d_name)) || lstat(tmp, &sta) == -1)
		ft_quit("minishell: erreur malloc", 2, comm);
	free(tmp);
	tmp = tmp2;
	if (sta.st_mode & S_IXUSR)
	{
		free(comm->tab[0]);
		comm->tab[0] = tmp;
		return (SUCCESS);
	}
	free(tmp);
	ft_putstr("Permission denied\n");
	return (FAILURE);
}

int	search_dir(char *bins, DIR *dir, t_comm *comm)
{
	struct dirent	*dirent;

	while ((dirent = readdir(dir)))
		if (ft_strcmp(dirent->d_name, comm->tab[0]) == 0)
		{
			return (s_d2(bins, dirent, comm));
		}
	return (FAILURE);
}

int	exec_comm(char **tab)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(tab[0], tab, env->env);
	else if (pid < 0)
	{
		ft_putendl("Fork failed to create a new process.\n");
		return (FAILURE);
	}
	wait(&pid);
	return (SUCCESS);
}

int	is_bin(t_comm *comm)
{
	int		x;
	char	**bins;
	DIR		*dir;

	x = 0;
	while (env->variable[x] && ft_strcmp(env->variable[x], "PATH") != 0)
		x++;
	if (!env->variable[x])
		return (FAILURE);
	if (!(bins = ft_strsplit(env->value[x], ':')))
		ft_quit("minishell: erreur malloc", 2, comm);
	x = 0;
	while (bins[x])
	{
		if (!(dir = opendir(bins[x])))
			ft_quit("minishell: erreur opendir dans le path", 2, comm);
		if (search_dir(bins[x], dir, comm) == SUCCESS)
		{
			ft_memdel((void **)bins);
			return (exec_comm(comm->tab));
		}
		++x;
	}
	ft_memdel((void **)bins);
	return (84);
}
