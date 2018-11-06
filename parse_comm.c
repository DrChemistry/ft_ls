/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:01:35 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/10/28 14:38:24 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

int		copy_lines(char *str, int x, char **tab, int b)
{
	int	c;
	int	in_between;

	c = 0;
	while (str[x] && (str[x] == ' ' || str[x] == '\t'))
		++x;
	in_between = 0;
	while (str[x])
	{
		if (str[x] == ';' && in_between == 0)
			break ;
		tab[b][c++] = str[x];
		if ((str[x] == '\"' && x == 0)
			|| (x > 0 && str[x] == '\"' && str[x - 1] != '\\'))
			in_between = in_between == 0 ? 1 : 0;
		++x;
	}
	c--;
	while (c > 0 && (tab[b][c] == ' ' || tab[b][c] == '\t'))
		--c;
	tab[b][++c] = '\0';
	return (x);
}

char	**ft_minishell_split(char *str, t_comm *comm)
{
	int		x;
	int		b;
	char	**tab;

	if (!(tab = malloc(sizeof(char *) * (ft_count_char(str, ';') + 2))))
		ft_quit("bash: malloc error", 2, comm);
	x = 0;
	b = 0;
	while (str[x])
	{
		if (str[x] && !(tab[b] = malloc(sizeof(char) * ft_strlen(str) + 1)))
			ft_quit("bash: malloc error", 2, NULL);
		x = copy_lines(str, x, tab, b);
		++b;
		if (str[x])
			++x;
	}
	tab[b] = NULL;
	if (b > 0 && tab[b - 1][0] == '\0')
		tab[b - 1] = NULL;
	free(str);
	return (tab);
}

int		parse_line(char *str, int x, char **tab, int b)
{
	int	c;
	int	in_between;

	c = 0;
	in_between = 0;
	while (str[x])
	{
		if ((str[x] == ' ' || str[x] == '\t') && in_between == 0)
			break ;
		if ((str[x] == '\"' && x == 0)
			|| (x > 0 && str[x] == '\"' && str[x - 1] != '\\'))
			in_between = in_between == 0 ? 1 : 0;
		else
			tab[b][c++] = str[x];
		++x;
	}
	tab[b][c] = '\0';
	return (x);
}

char	**comm_parsing(char *str)
{
	int		x;
	int		b;
	char	**tab;

	if (!(tab = malloc(sizeof(char *) * (ft_strlen(str) + 2))))
		ft_quit("bash: malloc error", 2, NULL);
	x = 0;
	b = 0;
	while (str[x])
	{
		if (!(tab[b] = malloc(sizeof(char) * ft_strlen(str) + 2)))
			ft_quit("bash: malloc error", 2, NULL);
		while (str[x] && (str[x] == ' ' || str[x] == '\t'))
			++x;
		if (str[x])
			x = parse_line(str, x, tab, b++);
	}
	tab[b] = NULL;
	return (tab);
}

void	parse_comm(t_comm *comm)
{
	while (comm)
	{
		comm->tab = comm_parsing(comm->ori);
		comm = comm->next;
	}
}
