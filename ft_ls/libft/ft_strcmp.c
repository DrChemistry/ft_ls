/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:49:53 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/29 09:33:33 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1 && s2 && (unsigned char)s1[x] && (unsigned char)s2[x]
			&& (unsigned char)s1[x] == (unsigned char)s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
