/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:25:35 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/14 18:15:23 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "ft_ls.h"

void			aff_time(char *str)
{
	int x;
	int tmp;

	x = 0;
	tmp = 0;
	while (str[x] && str[x] != ' ')
		++x;
	while (str[x] && tmp < 2)
	{
		ft_putchar(str[x++]);
		if (str[x] == ':')
			++tmp;
	}
}

struct s_sizes	*get_all_the_sizes(struct s_data *data)
{
	struct s_sizes	*length;

	if (!(length = malloc(sizeof(t_sizes))))
		return (NULL);
	length->size = 0;
	length->links = 0;
	length->char_owner = 0;
	length->char_grp = 0;
	length->blocks = 0;
	while (data->next)
	{
		if (ft_strlen(data->owner) > length->char_owner)
			length->char_owner = ft_strlen(data->owner);
		if (ft_strlen(data->grp) > length->char_grp)
			length->char_grp = ft_strlen(data->grp);
		if (ft_strlen(ft_itoa(data->file_stat.st_size)) > length->size)
			length->size = ft_strlen(ft_itoa(data->file_stat.st_size));
		if (ft_strlen(ft_itoa(data->file_stat.st_nlink)) > length->links)
			length->links = ft_strlen(ft_itoa(data->file_stat.st_nlink));
		length->blocks += data->file_stat.st_blocks;
		data = data->next;
	}
	return (length);
}

void aff_type(struct s_data *data)
{
	if (S_ISLNK(data->file_stat.st_mode))
		write(1, "l", 1);
	else if (S_ISBLK(data->file_stat.st_mode))
		write(1, "b", 1);
	else if (S_ISDIR(data->file_stat.st_mode))
		write(1, "d", 1);
	else if (S_ISCHR(data->file_stat.st_mode))
		write(1, "c", 1);
	else if (S_ISFIFO(data->file_stat.st_mode))
		write(1, "f", 1);
	else if (S_ISSOCK(data->file_stat.st_mode))
		write(1, "s", 1);
	else if (S_ISREG(data->file_stat.st_mode))
		write(1, "-", 1);
	else
		write(1, "u", 1);
}

void			aff_stuff(struct s_data *data, struct s_sizes *sizes, char *path)
{
	int	tmp;

	aff_type(data);
	ft_putchar((data->file_stat.st_mode & S_IRUSR) ? ('r') : ('-'));
	ft_putchar((data->file_stat.st_mode & S_IWUSR) ? ('w') : ('-'));
	ft_putchar((data->file_stat.st_mode & S_IXUSR) ? ('x') : ('-'));
	ft_putchar((data->file_stat.st_mode & S_IRGRP) ? ('r') : ('-'));
	ft_putchar((data->file_stat.st_mode & S_IWGRP) ? ('w') : ('-'));
	ft_putchar((data->file_stat.st_mode & S_IXGRP) ? ('x') : ('-'));
	ft_putchar((data->file_stat.st_mode & S_IROTH) ? ('r') : ('-'));
	ft_putchar((data->file_stat.st_mode & S_IWOTH) ? ('w') : ('-'));
	ft_putchar((data->file_stat.st_mode & S_IXOTH) ? ('x') : ('-'));
	ft_putstr("  ");
	tmp = sizes->links - ft_strlen(ft_itoa(data->file_stat.st_nlink));
	while (tmp-- > 0)
		ft_putchar(' ');
	ft_putnbr(data->file_stat.st_nlink);
	ft_putchar(' ');
	ft_putstr(data->owner);
	tmp = sizes->char_owner - ft_strlen(data->owner);
	while (tmp-- > 0)
		ft_putchar(' ');
}

void aff_link(char *path, char *name)
{
	char buff[1024];
	char *file;

	ft_bzero(buff, 1024);
	if (!(file = ft_strjoin(path, name)))
		exit (0);
	readlink(file, buff, 1024);
	ft_putstr(" -> ");
	ft_putstr(buff);
}

void			long_format(t_data *data, t_sizes *sizes, char *flags, char *path)
{
	int	tmp;

	ft_putstr("total ");
	ft_putnbr(sizes->blocks);
	ft_putchar('\n');
	while (data->next)
	{
		aff_stuff(data, sizes, path);
		ft_putstr("  ");
		ft_putstr(data->grp);
		tmp = sizes->char_grp - ft_strlen(data->grp);
		while (tmp-- > 0)
			ft_putchar(' ');
		ft_putstr("  ");
		tmp = sizes->size - ft_strlen(ft_itoa(data->file_stat.st_size));
		while (tmp-- > 0)
			ft_putchar(' ');
		ft_putnbr(data->file_stat.st_size);
		aff_time(ctime(&(data->file_stat.st_mtime)));
		ft_putchar(' ');
		ft_putstr(data->name);
		if (S_ISLNK(data->file_stat.st_mode))
			aff_link(path, data->name);
		ft_putchar('\n');
		data = data->next;
	}
}

void			aff_list(struct s_data *data, char *flags, char *path)
{
	struct s_sizes	*sizes;

	parse_sort(flags, data);
	while (data->last)
		data = data->last;
	if (flags[ft_findchar(flags, 'l')] == 'l')
	{
		if (!(sizes = get_all_the_sizes(data)))
			return ;
		long_format(data, sizes, flags, path);
	}
	else
	{
		while (data->next)
		{
			ft_putstr(data->name);
			if (data->next->next)
				ft_putchar(' ');
			data = data->next;
		}
		ft_putchar('\n');
	}
}
