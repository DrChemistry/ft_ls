/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:10:28 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/23 12:17:14 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static int	my_strlen(char const *str)
{
	int	x;

	x = 0;
	while (str && str[x])
		++x;
	return (x);
}

static char	**init_tab(char const *str, int *a, char c)
{
	char	**tab;
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (str && str[x])
	{
		if (str[x] == c)
			++i;
		++x;
	}
	if (!(tab = malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	x = 0;
	while (str && str[x] && str[x] == c)
	{
		(*a)++;
		++x;
	}
	return (tab);
}

static int	skip_car(char const *str, int x, char c)
{
	if (str[x])
		while (str && str[x] && str[x] == c)
			++x;
	return (x);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		x;
	int		i;
	int		b;

	x = 0;
	i = 0;
	if (!(tab = init_tab(s, &x, c)))
		return (NULL);
	while (s && s[x])
	{
		b = 0;
		if (!(tab[i] = malloc(sizeof(char) * (my_strlen(s) + 1))))
			return (NULL);
		while (s && s[x] && s[x] != c)
			tab[i][b++] = s[x++];
		tab[i][b] = '\0';
		x = skip_car(s, x, c);
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
