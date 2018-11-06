/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:18:22 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/02 12:52:22 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

char	*check_str(char *line, t_comm *comm)
{
	int		x;
	char	*tmp;
	char	*tmp2;
	char	*endl;

	x = 0;
	endl = "\n";
	while (ft_count_char(line, '\"') % 2 != 0)
	{
		ft_putstr("> ");
		if (get_next_line(0, &tmp) == -1)
			ft_quit("bash: erreur dans get_next_line", 2, comm);
		tmp2 = line;
		if (!(line = ft_strjoin(line, endl)))
			ft_quit("bash: malloc error", 2, comm);
		free(tmp2);
		tmp2 = line;
		if (!(line = ft_strjoin(line, tmp)))
			ft_quit("bash: malloc error", 2, comm);
		free(tmp);
		free(tmp2);
	}
	return (line);
}

t_comm	*fill_list(char **tab, t_comm *comm)
{
	t_comm	*tmp;
	int		x;

	x = 0;
	tmp = NULL;
	while (tab[x])
	{
		if (!comm && !(comm = malloc(sizeof(t_comm) * 1)))
			ft_quit("bash: malloc error", 2, comm);
		if (!(comm->ori = ft_strdup(tab[x++])))
			ft_quit("bash: malloc error", 2, comm);
		if (tmp)
			tmp->next = comm;
		comm->last = tmp;
		comm->next = NULL;
		tmp = comm;
		comm = comm->next;
	}
	comm = tmp;
	while (comm->last)
		comm = comm->last;
	return (comm);
}

t_comm	*get_comms(t_comm *comm)
{
	char	*line;
	char	**tab;
	char	*tmp;
	int		x;

	line = NULL;
	tab = NULL;
	if (!(comm = malloc(sizeof(t_comm) * 1)) || get_next_line(0, &line) == -1)
		ft_quit("bash: malloc error", 2, comm);
	if (line)
		tab = ft_minishell_split(check_str(line, comm), comm);
	if (!tab || !tab[0])
	{
		if (tab)
			free(tab);
		free(comm);
		return (NULL);
	}
	comm = fill_list(tab, comm);
	x = 0;
	while (tab[x])
		free(tab[x++]);
	free(tab);
	parse_comm(comm);
	return (comm);
}
