/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:40:01 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/30 13:16:17 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int tmp;
	int x;
	int i;

	x = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (to_find && str[x])
	{
		i = 0;
		if (str[x] == to_find[i])
		{
			tmp = x;
			while (str[x] == to_find[i] && to_find[i])
			{
				++x;
				++i;
			}
			if (!to_find[i])
				return ((char *)(str + tmp));
			x = tmp;
		}
		++x;
	}
	return (NULL);
}
