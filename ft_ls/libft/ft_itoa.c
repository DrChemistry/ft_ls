/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:18:09 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/12/01 14:28:08 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_rev_str(char *str)
{
	int x;
	int b;
	int tmp;

	b = 0;
	x = 0;
	while (str[b])
		++b;
	while (x < --b)
	{
		tmp = str[x];
		str[x++] = str[b];
		str[b] = tmp;
	}
	return (str);
}

static char	*ft_init(int n)
{
	int				x;
	unsigned int	tmp;
	char			*str;

	tmp = n < 0 ? -n : n;
	x = 1;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		++x;
	}
	if (!(str = malloc(sizeof(char) * (x + 1))))
		return (NULL);
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	tmp;
	int				x;

	if (!(str = ft_init(n)))
		return (NULL);
	x = 0;
	tmp = n < 0 ? -n : n;
	while (tmp != 0)
	{
		str[x++] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	if (x == 0)
		str[x++] = '0';
	if (n < 0)
		str[x++] = '-';
	str[x] = '\0';
	return (ft_rev_str(str));
}
