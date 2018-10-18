/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_comm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:40:21 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/10/18 15:40:28 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include "minishell.h"

int exec_comm(char **tab, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(tab[0], tab, env->env);
	else if (pid < 0)
	{
		ft_putendl("Fork failed to create a new process.\n");
		return (-1);
	}
	wait(&pid);
	return (1);
}

int check_exec(t_comm *comm, t_env *env)
{
	struct stat sta;
	int x;

	x = 0;
	if (lstat(comm->tab[0], &sta) == -1)
		return (NB_BUILT_IN);
	if (sta.st_mode & S_IXUSR)
	{
		if (exec_comm(comm->tab, env) == -1)
			return (NB_BUILT_IN);
	}
	return (SUCCESS);
}
