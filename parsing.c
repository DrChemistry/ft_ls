/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:49:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/14 18:24:40 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ascii_sort(struct s_data *data)
{
	struct s_data	*tmp;

	while (data->next->next)
	{
		if (ft_strcmp(data->name, data->next->name) > 0)
		{
			tmp = data->next;
			tmp->last = data->last;
			data->next = tmp->next;
			data->last = tmp;
			tmp->next = data;
			if (data->next)
				data->next->last = data;
			if (tmp->last)
				tmp->last->next = tmp;
			while (data->last)
				data = data->last;
		}
		else
			data = data->next;
	}
}

void	time_sort(struct s_data *data)
{
	struct s_data	*tmp;

	while (data->next->next)
	{
		if (data->time < data->next->time)
		{
			tmp = data->next;
			tmp->last = data->last;
			data->next = tmp->next;
			data->last = tmp;
			tmp->next = data;
			if (data->next)
				data->next->last = data;
			if (tmp->last)
				tmp->last->next = tmp;
			while (data->last)
				data = data->last;
		}
		else
			data = data->next;
	}
}

void	reverse_list(struct s_data *data)
{
	while (data->next)
	{
		data = data->next;
	}
}

void	parse_sort(char *flags, struct s_data *data)
{
	int	x;

	x = -1;
	ascii_sort(data);
	while (data->last)
		data = data->last;
	while (flags[++x])
	{
		if (flags[x] == 't')
			time_sort(data);
		if (flags[x] == 'r')
			reverse_list(data);
	}
}
