/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:33:51 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/09/17 15:35:29 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_ls.h"

int	is_reverse(struct s_data *data)
{
	struct s_data	*begin;
	int				x;
	int				b;

	x = 0;
	begin = data;
	while (data && data->next)
	{
		data = data->next;
		x++;
	}
	data = begin;
	b = 0;
	while (data && data->next && data->next->next)
	{
		if (ft_strcmp(data->name, data->next->name) > 0)
		{
			b++;
		}
		data = data->next;
	}
	while (data)
		data = data->last;
	return (b < x / 2 ? 1 : 0);
}
