/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:53:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/10/28 16:53:58 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	check_doublons(char *flags, char c)
{
	int x;

	x = 0;
	while (flags[x])
	{
		if (flags[x] == c)
			return ;
		++x;
	}
	flags[x] = c;
	return ;
}

int		flags_gestion(char *flags, char **av, int x, char *list)
{
	int b;

	x = -1;
	while (++x < ft_strlen(flags))
		flags[x] = '\0';
	x = 1;
	while (av[x] && av[x][0] == '-')
	{
		b = 1;
		while (av[x][b])
		{
			if (av[x][b] == list[ft_findchar(list, av[x][b])])
				check_doublons(flags, av[x][b++]);
			else
			{
				ft_putchar_fd(av[x][b], 2);
				ft_putendl_fd(" :is an illegal option", 2);
				return (FAILURE);
			}
		}
		++x;
	}
	return (SUCCESS);
}
