/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:34:47 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/29 08:40:41 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		x;

	if (!(str = ft_strnew((size_t)ft_strlen((char *)s))))
		return (NULL);
	x = 0;
	while (*s)
		str[x++] = f((char)*s++);
	str[x] = '\0';
	return (str);
}
