/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:21:28 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/30 13:06:31 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		x;
	char	*str;

	if (!(str = malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	x = 0;
	while (src[x])
	{
		str[x] = src[x];
		++x;
	}
	str[x] = '\0';
	return (str);
}
