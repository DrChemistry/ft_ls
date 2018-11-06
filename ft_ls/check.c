/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:43:28 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/18 19:57:29 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include "ft_ls.h"

int		is_dir(char *name)
{
	DIR *dir;

	if (!(dir = opendir(name)))
		return (FAILURE);
	closedir(dir);
	return (SUCCESS);
}

int		is_file(char *name)
{
	struct stat file;

	if (stat(name, &file) == 0)
		return (SUCCESS);
	return (FAILURE);
}

void	free_data(t_data *data)
{
	while (data->last)
		data = data->last;
	while (data && data->next)
	{
		free(data->name);
		data = data->next;
		free(data->last);
	}
	free(data);
}
