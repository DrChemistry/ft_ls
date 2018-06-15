/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:48:49 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/23 12:13:54 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start--)
		s++;
	ft_strncpy(str, (char *)s, len);
	str[len] = '\0';
	return (str);
}
