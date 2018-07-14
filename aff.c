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
		if (ft_strlen(ft_itoa(data->size)) > length->size)
			length->size = ft_strlen(ft_itoa(data->size));
		if (ft_strlen(ft_itoa(data->nb_links)) > length->links)
			length->links = ft_strlen(ft_itoa(data->nb_links));
		length->blocks += data->blocks;
		data = data->next;
	}
	return (length);
}

void aff_type(struct s_data *data)
{
	if (S_ISLNK(data->mode))
		write(1, "l", 1);
	else if (S_ISBLK(data->mode))
		write(1, "b", 1);
	else if (S_ISDIR(data->mode))
		write(1, "d", 1);
	else if (S_ISCHR(data->mode))
		write(1, "c", 1);
	else if (S_ISFIFO(data->mode))
		write(1, "f", 1);
	else if (S_ISSOCK(data->mode))
		write(1, "s", 1);
	else if (S_ISREG(data->mode))
		write(1, "-", 1);
	else
		write(1, "u", 1);
}

void			aff_stuff(struct s_data *data, struct s_sizes *sizes)
{
	int	tmp;

	aff_type(data);
	ft_putchar((data->mode & S_IRUSR) ? ('r') : ('-'));
	ft_putchar((data->mode & S_IWUSR) ? ('w') : ('-'));
	ft_putchar((data->mode & S_IXUSR) ? ('x') : ('-'));
	ft_putchar((data->mode & S_IRGRP) ? ('r') : ('-'));
	ft_putchar((data->mode & S_IWGRP) ? ('w') : ('-'));
	ft_putchar((data->mode & S_IXGRP) ? ('x') : ('-'));
	ft_putchar((data->mode & S_IROTH) ? ('r') : ('-'));
	ft_putchar((data->mode & S_IWOTH) ? ('w') : ('-'));
	ft_putchar((data->mode & S_IXOTH) ? ('x') : ('-'));
	ft_putstr("  ");
	tmp = sizes->links - ft_strlen(ft_itoa(data->nb_links));
	while (tmp-- > 0)
		ft_putchar(' ');
	ft_putnbr(data->nb_links);
	ft_putchar(' ');
	ft_putstr(data->owner);
	tmp = sizes->char_owner - ft_strlen(data->owner);
	while (tmp-- > 0)
		ft_putchar(' ');
}

void			long_format(struct s_data *data, t_sizes *sizes, char *flags)
{
	int	tmp;

	ft_putstr("total ");
	ft_putnbr(sizes->blocks);
	ft_putchar('\n');
	while (data->next)
	{
		aff_stuff(data, sizes);
		ft_putstr("  ");
		ft_putstr(data->grp);
		tmp = sizes->char_grp - ft_strlen(data->grp);
		while (tmp-- > 0)
			ft_putchar(' ');
		ft_putstr("  ");
		tmp = sizes->size - ft_strlen(ft_itoa(data->size));
		while (tmp-- > 0)
			ft_putchar(' ');
		ft_putnbr(data->size);
		ft_putchar(' ');
		aff_time(ctime(&(data->time)));
		ft_putchar(' ');
		ft_putstr(data->name);
		data = data->next;
		ft_putchar('\n');
	}
}

void			aff_list(struct s_data *data, char *flags)
{
	struct s_sizes	*sizes;

	parse_sort(flags, data);
	while (data->last)
		data = data->last;
	if (flags[ft_findchar(flags, 'l')] == 'l')
	{
		if (!(sizes = get_all_the_sizes(data)))
			return ;
		long_format(data, sizes, flags);
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
