/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_comm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:16:52 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/02 12:53:12 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include "minishell.h"

int	built_in(t_comm *comm, char **b_in, int (*ft_tab[])(t_comm *data))
{
	int x;

	x = 0;
	while (b_in[x] && ft_strcmp(comm->tab[0], b_in[x]) != 0)
		++x;
	if (x < NB_BUILT_IN)
		return (ft_tab[x](comm));
	return (84);
}

int	file_exec(char **tab)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(&tab[0][2], tab, env->env);
	else if (pid < 0)
	{
		ft_putendl("Fork failed to create a new process.\n");
		return (FAILURE);
	}
	wait(&pid);
	return (SUCCESS);
}

int	exec_file(t_comm *comm)
{
	struct stat sta;

	if (lstat(&comm->tab[0][2], &sta) == -1)
	{
		ft_putendl_fd("No such file or directory", 2);
		return (FAILURE);
	}
	if (sta.st_mode & S_IXUSR)
	{
		if (file_exec(comm->tab) == -1)
			return (FAILURE);
		else
			return (SUCCESS);
	}
	ft_putendl_fd("Not an exectuable file", 2);
	return (FAILURE);
}

int	exec_comms(t_comm *com, char **bn, int (*fab[])(t_comm *data))
{
	int back;

	back = 0;
	while (com)
	{
		if (com->tab[0] && ft_strncmp(com->tab[0], "./", 2) == 0)
			back = exec_file(com);
		if (com->tab[0] && ft_strncmp(com->tab[0], "./", 2) != 0)
		{
			back = built_in(com, bn, fab);
			if (back == 84)
				back = is_bin(com);
			//printf("test\n");
			if (back == 84)
				ft_putendl_fd("Command not found", 2);
		}
		com = com->next;
	}
	return (back);
}
