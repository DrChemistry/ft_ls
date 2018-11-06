/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 08:22:28 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/30 13:15:11 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int	tmp;
	int tmp2;
	int	x;
	int	i;

	x = -1;
	while (str[++x] && (int)n > x)
	{
		i = 0;
		if (str[x] == to_find[i] || to_find[0] == '\0')
		{
			tmp = x;
			tmp2 = n;
			while (str[x] == to_find[i] && to_find[i] && (int)n > x)
			{
				x++;
				++i;
			}
			if (!to_find[i])
				return ((char *)(str + tmp));
			x = tmp;
			n = tmp2;
		}
	}
	return (NULL);
}
