/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:25:35 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/08 10:27:03 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void aff_list(struct s_data *data, char *flags)
{
	parse_sort(flags, data);
	if (flags[ft_findchar(flags, 'l')] == 'l')
	 exit (0);
	while (data->next)
	{
			ft_putstr(data->name);
			if (data->next->next)
				ft_putchar('\t');
			data = data->next;
	}
	ft_putchar('\n');
}

int print_files(char **files, char *flags)
{
	int x;

	x = 0;
	while (files[x])
		printf("files:%s\n", files[x++]);
	return (SUCCESS);
}
