/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:58:34 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/29 08:42:48 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		x;
	int		lim;
	int		i;

	x = 0;
	lim = ft_strlen((char *)s) - 1;
	if (!(str = ft_strnew((size_t)ft_strlen((char *)s))))
		return (NULL);
	while ((s[lim] == ' ' || s[lim] == '\t' || s[lim] == '\n') && lim > 0)
		--lim;
	while (s[x] && (s[x] == ' ' || s[x] == '\t' || s[x] == '\n'))
		++x;
	i = 0;
	while (x <= lim)
		str[i++] = s[x++];
	str[i] = '\0';
	return (str);
}
