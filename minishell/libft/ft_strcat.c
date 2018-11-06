/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:34:06 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/30 13:07:45 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int b;
	int x;

	x = 0;
	while (dest && dest[x])
		++x;
	b = 0;
	while (src[b])
		dest[x++] = src[b++];
	dest[x] = '\0';
	return (dest);
}
