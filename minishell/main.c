/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:41:32 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/02 12:57:28 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	delete_comms(t_comm *comm)
{
	int		x;
	t_comm	*tmp;

	while (comm->last)
		comm = comm->last;
	while (comm)
	{
		x = 0;
		while (comm && comm->tab[x])
			free(comm->tab[x++]);
		free(comm->tab);
		if (comm->ori)
			free(comm->ori);
		tmp = comm;
		comm = comm->next;
		free(tmp);
	}
}

int		main(int ac, char **av, char **env_or)
{
	t_comm	*comm;
	int		(*ft_tab[NB_BUILT_IN + 1])(t_comm *data);
	char	**built_in;
	int		back;
	char	*tab[NB_BUILT_IN + 1];

	init_env(env_or, comm);
	if (!(built_in = init_tab(ft_tab, tab)))
		ft_quit("bash: erreur built_in", 2, comm);
	while (1)
	{
		print_prompt(comm);
		comm = get_comms(comm);
		if (comm)
		{
			back = exec_comms(comm, built_in, ft_tab);
			delete_comms(comm);
			push_env();
		}
	}
	ft_quit("test", 1, comm);
	return (SUCCESS);
}
