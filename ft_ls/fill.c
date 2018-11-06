/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:19:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/08/08 15:18:39 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
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

	if (lstat(file, &file_stat) == FAILURE)
		return (FAILURE);
	data->file_stat = file_stat;
	if (!(owneruid = getpwuid(file_stat.st_uid)))
		return (FAILURE);
	if (!(grpuid = getgrgid(file_stat.st_gid)))
		return (FAILURE);
	data->owner = owneruid->pw_name;
	data->grp = grpuid->gr_name;
	if (!(data->name = ft_strdup(file_dirent)))
		return (FAILURE);
	return (SUCCESS);
}

int		fill_data(t_data *data, char *name, char *flags, char *repo)
{
	DIR				*dir;
	struct dirent	*file_dirent;
	char			*file;

	dir = opendir(name);
	if (errno == 13)
		return (SUCCESS);
	else if (!dir)
		return (FAILURE);
	while ((file_dirent = readdir(dir)))
		if (file_dirent->d_name[0] != '.'
			|| (file_dirent->d_name[0] == '.'
				&& flags[ft_findchar(flags, 'a')] == 'a'))
		{
			if (!(file = get_path_file(name, repo, file_dirent->d_name))
					|| fill(data, file, file_dirent->d_name) == FAILURE
					|| !(data->next = malloc(sizeof(struct s_data))))
				return (FAILURE);
			data->next->last = data;
			data = data->next;
			free(file);
		}
	closedir(dir);
	data->next = NULL;
	return (SUCCESS);
}

int		ft_ls2(t_data *data, char *flags, char **dires, int x)
{
	aff_list(data, flags, dires[x], 1);
	if (flags[ft_findchar(flags, 'R')] == 'R')
		if (recursive_option(dires[x], flags, data) == FAILURE)
			return (FAILURE);
	if (dires[x + 1])
		ft_putstr("\n");
	free_data(data);
	return (SUCCESS);
}
