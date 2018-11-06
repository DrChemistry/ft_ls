/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:24:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/29 09:32:41 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		x;

	if (!(str = malloc(sizeof(char) * (int)size + 1)))
		return (NULL);
	x = 0;
	while (x < (int)size)
		str[x++] = 0;
	str[x] = 0;
	return (str);
}
