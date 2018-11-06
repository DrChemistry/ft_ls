/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:21:46 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/09/11 17:23:48 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_tab(char **tab)
{
	int		x;
	int		b;
	char	*tmp;

	x = 0;
	b = 0;
	while (tab[b])
		++b;
	b--;
	while (x < b)
	{
		tmp = tab[x];
		tab[x++] = tab[b];
		tab[b--] = tmp;
	}
}