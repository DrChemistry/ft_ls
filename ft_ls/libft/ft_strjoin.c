/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:52:38 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/23 12:21:37 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		x;

	x = 0;
	if (!(str = malloc(sizeof(char) *
					(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1))))
		return (NULL);
	while (*s1)
		str[x++] = *s1++;
	while (*s2)
		str[x++] = *s2++;
	str[x] = '\0';
	return (str);
}
