/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:17:41 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/10/26 13:57:28 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int		ft_exit(t_comm *data)
{
	ft_quit("exit", 1, data);
	return (0);
}

void	ft_quit(char *msg, int outp, t_comm *comm)
{
	int		x;
	t_comm	*tmp;

	x = 0;
	while (env && env->env[x])
	{
		free(env->env[x]);
		free(env->variable[x]);
		free(env->value[x++]);
	}
	while (comm)
	{
		x = 0;
		while (comm && comm->tab[x])
			free(comm->tab[x++]);
		if (comm->ori)
			free(comm->ori);
		tmp = comm;
		comm = comm->last;
		free(tmp);
	}
	ft_putendl_fd(msg, outp);
	exit(1);
}
