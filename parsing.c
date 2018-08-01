/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:49:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/08/01 16:01:59 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_ls.h"

void	ascii_sort(struct s_data *data)
{
	struct s_data	*tmp;

	while (data && data->next && data->next->next)
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

	while (data && data->next && data->next->next)
	{
		if (data->file_stat.st_mtime < data->next->file_stat.st_mtime)
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
	t_data	*head;
	t_data	*temp;

	if (!data->last && !data->next)
		return ;
	head = data;
	while (data)
	{
		temp = data->last;
		data->last = data->next;
		data->next = temp;
		data = data->last;
	}
	data = head;
	if (data)
	{
		while (data && data->last)
			data = data->last;
		data->next->last = NULL;
		data->next = NULL;
		data->last = head;
		head->next = data;
	}
}

t_data	*parse_sort(char *flags, struct s_data *data)
{
	int	x;

	x = -1;
	ascii_sort(data);
	while (data->last)
		data = data->last;
	if (flags[ft_findchar(flags, 't')] == 't')
		time_sort(data);
	while (data->last)
		data = data->last;
	if (flags[ft_findchar(flags, 'r')] == 'r')
		reverse_list(data);
	while (data->last)
		data = data->last;
	return (data);
}
