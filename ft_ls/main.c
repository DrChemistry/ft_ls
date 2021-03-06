/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:13:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/18 20:07:52 by adi-rosa         ###   ########.fr       */
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

int	recursive_option(char *curr_dires, char *flags, t_data *data)
{
	char	*dires[2];
	char	*repo;

	dires[1] = NULL;
	repo = "/";
	while (data->last)
		data = data->last;
	while (data->next)
	{
		if (ft_strcmp(data->name, ".") != 0 && ft_strcmp(data->name, "..") != 0)
		{
			if (S_ISDIR(data->file_stat.st_mode))
			{
				if (!(dires[0] = get_path_file(curr_dires, repo, data->name)))
					return (FAILURE);
				ft_putchar('\n');
				ft_putstr(dires[0]);
				ft_putstr(":\n");
				if (ft_ls(dires, flags, NULL) == FAILURE)
					return (FAILURE);
			}
		}
		data = data->next;
	}
	return (SUCCESS);
}

int	ft_ls(char **dires, char *flags, char **files)
{
	int				x;
	struct s_data	*data;

	x = -1;
	while (dires[++x])
	{
		if (!(data = malloc(sizeof(struct s_data))))
			return (FAILURE);
		data->last = NULL;
		if (fill_data(data, dires[x], flags, "/") == FAILURE)
			return (FAILURE);
		if (errno != 13)
		{
			if ((x == 0 && dires[x + 1]) || x > 0 || (files && files[0]))
			{
				ft_putstr(dires[x]);
				ft_putstr(":\n");
			}
			if (ft_ls2(data, flags, dires, x) == FAILURE)
				return (FAILURE);
		}
		else
			errno = 0;
	}
	return (SUCCESS);
}

int	ft_files(char **files, char *flags, char **dires, int x)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (FAILURE);
	data->last = NULL;
	while (files[++x])
	{
		fill(data, files[x], files[x]);
		if (!(data->next = malloc(sizeof(t_data))))
			return (FAILURE);
		data->next->last = data;
		data = data->next;
	}
	data->next = NULL;
	while (data->last)
		data = data->last;
	aff_list(data, flags, "./", 0);
	if (dires && dires[0])
		ft_putchar('\n');
	free_data(data);
	return (SUCCESS);
}

int	separate_file(char **name, char *flags, int size)
{
	char	**dires;
	char	**files;
	int		x;
	int		c;
	int		b;

	x = 0;
	if (!(dires = malloc(sizeof(char *) * size))
			|| !(files = malloc(sizeof(char *) * size)))
		return (FAILURE);
	b = 0;
	c = 0;
	while (name[x])
		if (is_dir(name[x]) == SUCCESS)
			dires[b++] = name[x++];
		else if (is_file(name[x]) == SUCCESS)
			files[c++] = name[x++];
	files[c] = NULL;
	dires[b] = NULL;
	if (sort1(dires, flags) || (files[0] && ft_files(files, flags, dires, -1)
		== FAILURE) || ft_ls(dires, flags, files) == FAILURE)
		return (FAILURE);
	free(files);
	free(dires);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	int		x;
	int		b;
	char	flags[6];
	char	**files;

	if ((x = flags_gestion(flags, av, x)) == FAILURE
			|| !(files = malloc(sizeof(char *) * (ac + 1))))
		return (FAILURE);
	b = 0;
	if (!av[x])
		files[b++] = "./";
	while (av[x])
		if (is_dir(av[x]) == SUCCESS || is_file(av[x]) == SUCCESS)
			files[b++] = av[x++];
		else
		{
			ft_putstr("ls: ");
			ft_putstr(av[x++]);
			ft_putstr(": No such file or directory\n");
		}
	files[b] = NULL;
	if (separate_file(files, flags, b + 1) == FAILURE)
		return (FAILURE);
	free(files);
	return (SUCCESS);
}
