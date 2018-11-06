/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:03:00 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/10/28 16:06:49 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tab_dup(char **tab)
{
	char	**res;
	int		x;

	x = 0;
	while (tab[x])
		++x;
	if (!(res = malloc(sizeof(char *) * (x + 1))))
		return (NULL);
	x = 0;
	while (tab[x])
	{
		if (!(res[x] = ft_strdup(tab[x])))
			return (NULL);
		++x;
	}
	res[x] = NULL;
	return (res);
}
