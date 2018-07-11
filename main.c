/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:13:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/08 10:48:13 by adi-rosa         ###   ########.fr       */
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

int	recursive_option(char *curr_dires, char *flags, struct s_data *data)
{
	char	*dires[2];
	char	*repo;

	dires[1] = NULL;
	repo = "/";
	while (data->next)
	{
		if (ft_strcmp(data->name, ".") != 0 && ft_strcmp(data->name, "..") != 0)
		{
		 	if (S_ISDIR(data->mode))
			{
				printf("recusive name verif[%s]\n", data->name);
				if (!(dires[0] = get_path_file(curr_dires, repo, data->name)))
					return (FAILURE);
				if (ft_ls(dires, flags) == FAILURE)
					return (FAILURE);
			}
		}
		data = data->next;
	}
	return (SUCCESS);
}

int	ft_ls(char **dires, char *flags)
{
	int				x;
	struct s_data	*data;
	char			*repo;

	x = 0;
	repo = "/";
	while (dires[x])
	{
		if (!(data = malloc(sizeof(struct s_data))))
			return (FAILURE);
		data->last = NULL;
		if (fill_data(data, dires[x], flags, repo) == FAILURE)
			return (FAILURE);
		//printf("dires: %s\nlist_name: %s\n", dires[x], data->name);
		if ((x == 0 && dires[x + 1]) || x > 0)
		{
			ft_putstr(dires[x]);
			ft_putstr(":\n");
		}
		aff_list(data, flags);
		if (flags[ft_findchar(flags, 'R')] == 'R')
			if (recursive_option(dires[x], flags, data) == FAILURE)
				return (FAILURE);
		if (dires[++x])
			ft_putstr("\n");
	}
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
	if (print_files(files, flags) == FAILURE
			|| ft_ls(dires, flags) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	int		x;
	int		b;
	char	flags[6];
	char	**files;

	x = 1;
	if ((x = flags_gestion(flags, av, x)) == FAILURE)
		return (FAILURE);
	b = 0;
	if (!(files = malloc(sizeof(char *) * (ac + 1))))
		return (FAILURE);
	while (av[x])
	{
		if (is_dir(av[x]) == SUCCESS || is_file(av[x]) == SUCCESS)
			files[b++] = av[x++];
		else
		{
			ft_putstr("ls: ");
			ft_putstr(av[x++]);
			ft_putstr(": No such file or directory\n");
		}
	}
	if (b == 0)
		files[b++] = "./";
	files[b] = NULL;
	return (separate_file(files, flags, b + 1));
}
