/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asciisort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:19:27 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/09/11 17:24:40 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_asciisort(char **tab)
{
	char	*tmp;
	int		x;

	x = 0;
	while (tab[x] && tab[x + 1])
	{
		if (ft_strcmp(tab[x], tab[x + 1]) > 0)
		{
			tmp = tab[x];
			tab[x] = tab[x + 1];
			tab[x + 1] = tmp;
			x = 0;
		}
		else
			++x;
	}
}
