/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:19:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/08 10:51:55 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include "ft_ls.h"

char	*get_path_file(char *name, char *repo, char *d_name)
{
	char	*file;

	if (name[ft_strlen(name) - 1] != '/')
	{
		if (!(file = ft_strjoin(ft_strjoin(name, repo), d_name)))
			return (NULL);
	}
	else
	{
		if (!(file = ft_strjoin(name, d_name)))
			return (NULL);
	}
	return (file);
}

int		fill(struct s_data *data, char *file, char *file_dirent)
{
	struct passwd	*owneruid;
	struct group	*grpuid;
	struct stat		file_stat;

	if (stat(file, &file_stat) == FAILURE)
		return (FAILURE);
	data->nb_links = file_stat.st_nlink;
	data->size = file_stat.st_size;
	data->blocks = file_stat.st_blocks;
	if (!(owneruid = getpwuid(file_stat.st_uid)))
		return (FAILURE);
	if (!(grpuid = getgrgid(file_stat.st_gid)))
		return (FAILURE);
	data->owner = owneruid->pw_name;
	data->grp = grpuid->gr_name;
	data->time = file_stat.st_mtime;
	if (!(data->name = ft_strdup(file_dirent)))
		return (FAILURE);
	data->mode = file_stat.st_mode;
	return (SUCCESS);
}

int		fill_data(t_data *data, char *name, char *flags, char *repo)
{
	DIR				*dir;
	struct dirent	*file_dirent;
	char			*file;

	if (!(dir = opendir(name)))
		return (FAILURE);
	while ((file_dirent = readdir(dir)))
	{
		if (file_dirent->d_name[0] != '.'
			|| (file_dirent->d_name[0] == '.'
				&& flags[ft_findchar(flags, 'a')] == 'a'))
		{
			if (!(file = get_path_file(name, repo, file_dirent->d_name)))
				return (FAILURE);
			if (fill(data, file, file_dirent->d_name) == FAILURE)
				return (FAILURE);
			if (!(data->next = malloc(sizeof(struct s_data))))
				return (FAILURE);
			data->next->last = data;
			data = data->next;
			free(file);
		}
	}
	data->next = NULL;
	return (SUCCESS);
}
