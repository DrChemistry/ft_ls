/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:43:17 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/14 18:17:55 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

int		flags_gestion(char *flags, char **av, int x)
{
	int b;

	x = -1;
	while (++x < 6)
		flags[x] = '\0';
	x = 1;
	while (av[x] && av[x][0] == '-')
	{
		b = 1;
		while (av[x][b])
		{
			if (av[x][b] == 'l' || av[x][b] == 'a'
					|| av[x][b] == 'R' || av[x][b] == 'r'
					|| av[x][b] == 't')
				check_doublons(flags, av[x][b++]);
			else
				return (ft_puterror("ls: illegal option -- \n", FAILURE));
		}
		++x;
	}
	return (x);
}
