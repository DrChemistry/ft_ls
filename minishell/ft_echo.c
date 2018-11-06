/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:28:51 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/10/24 15:28:52 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_echo(t_comm *data)
{
	int x;
	int flags;

	x = 1;
	flags = 0;
	if (data->tab[1] && ft_strcmp(data->tab[1], "-n") == 0)
	{
		flags = 1;
		x = 2;
	}
	while (data->tab[x])
	{
		ft_putstr(data->tab[x++]);
		ft_putstr(" ");
	}
	if (flags == 0)
		ft_putchar('\n');
	return (SUCCESS);
}
