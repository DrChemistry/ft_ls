/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:53:17 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/12/01 14:41:36 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	x;

	x = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[x] && (unsigned char)s2[x]
			&& (unsigned char)s1[x] == (unsigned char)s2[x] && --n > 0)
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
