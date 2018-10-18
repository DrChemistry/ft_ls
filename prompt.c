/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:56:33 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/09/24 09:56:36 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int print_prompt(void)
{
	char	*buf;
	int		x;

	if (!(buf = malloc(sizeof(char) * 128)))
		return (FAILURE);
	x = 1;
	while (!(getcwd(buf, 128)))
	{
		if (!(buf = malloc(sizeof(char) * (128 * x))))
			return (FAILURE);
		++x;
	}
	ft_putstr(GREEN);
	ft_putstr(buf);
	ft_putstr(RESET);
	write(1, "$>", 2);
	return (SUCCESS);
}
