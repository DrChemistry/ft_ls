/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:06:06 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/09/24 10:06:07 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

char **split_args(char *line, int x, char **tab)
{
	int b;
	int c;
	int a;
	int count;

	b = 1;
	count = 0;
	c = 0;
	if (!(tab[1] = malloc(sizeof(char) * ft_strlen(line) + 2)))
		return (NULL);
	while (line[x])
	{
		if (line[x] == ' ' && count == 0)
			{
				tab[b][c] = '\0';
				++b;
				c = 0;
				while (line[x] && line[x] == ' ')
					++x;
				--x;
				if (!(tab[b] = malloc(sizeof(char) * ft_strlen(line) + 2)))
					return (NULL);
			}
		else if (line[x] == '\"' && count == 0)
			count = 1;
		else if (line[x] == '\"' && count == 1)
			count = 0;
		else
			tab[b][c++] = line[x];
		x++;
	}
	if (line[x - 1] != ' ')
		tab[b++][c] = '\0';
	tab[b] = NULL;
	return (tab);
}

char *check_even(char *line)
{
	char *space;
	char **comm;
	char *tmp;

	space = "\n";
	if (!(comm = malloc(sizeof(char *) * 1)))
		return (NULL);
	while (ft_count_char(line, '\"') % 2 != 0)
	{
		tmp = line;
		if (!(line = ft_strjoin(line, space)))
			return (NULL);
		free(tmp);
		ft_putstr(">");
		tmp = line;
		if (get_next_line(1, comm) == -1 || !(line = ft_strjoin(line, comm[0])))
			return (NULL);
		free(comm[0]);
		free(comm);
		//free(tmp);
	}
	return (line);
}

char		**ft_commsplit(char *line)
{
	int x;
	char **tab;
	int c;

	if (!(line = check_even(line)))
		return (NULL);
	if (!(tab = malloc(sizeof(char *) * (ft_strlen(line) + 2)))
			|| !(tab[0] = malloc(sizeof(char) * ft_strlen(line) + 2)))
		return (NULL);
	x = 0;
	c = 0;
	while (line[x] && line[x] != ' ' && line[x] != '\t')
		tab[0][c++] = line[x++];
	tab[0][c] = '\0';
	tab[1] = NULL;
	if (line[x])
		{
			while (line[x] == ' ' || line[x] == '\t')
				++x;
			if (!split_args(line, x, tab))
				return (NULL);
		}
	return (tab);
}

t_comm	*parse_command(char *line)
{
	t_comm *comm;

	if (!(comm = malloc(sizeof(t_comm))))
		return (NULL);
	if (!(comm->tab = ft_commsplit(line)))
		return (NULL);
	comm->last = NULL;
	comm->next = NULL;
	comm->ori = line;
	return (comm);
}
