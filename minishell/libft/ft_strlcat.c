/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:27:01 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/12/01 14:51:46 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t x;
	size_t b;
	size_t tmp;
	size_t tmp2;

	x = 0;
	b = 0;
	tmp = ft_strlen(dest);
	tmp2 = ft_strlen(src);
	while (dest[x] && x < size)
		++x;
	while (src[b] && (int)x < (int)size - 1)
		dest[x++] = src[b++];
	if (size > 0 && tmp < size)
		dest[x] = '\0';
	return (size < tmp ? size + tmp2 : tmp + tmp2);
}
