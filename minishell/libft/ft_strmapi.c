/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:39:21 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/29 08:41:26 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		x;

	x = 0;
	if (!(str = ft_strnew((size_t)ft_strlen((char *)s))))
		return (NULL);
	while (s[x])
	{
		str[x] = f(x, s[x]);
		++x;
	}
	return (str);
}
