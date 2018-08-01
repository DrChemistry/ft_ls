/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:51:53 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/08/01 16:01:24 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/xattr.h>
#include "ft_ls.h"

void	aff_year(char *str, int x, int tmp)
{
	while (str[x] && x < 10)
	{
		ft_putchar(str[x]);
		if (str[x] == ' ')
			++tmp;
		++x;
	}
	ft_putchar(' ');
	str[ft_strlen(str) - 1] = '\0';
	ft_putstr(str + ft_strlen(str) - 5);
}

void	aff_acl(char *path)
{
	if (!path)
		exit(0);
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
	free(path);
	ft_putchar(' ');
}

void	aff_time(char *str)
{
	int		x;
	int		tmp;
	time_t	t;
	char	*cr_time;

	x = 0;
	tmp = 0;
	if (!(str = ft_strdup(str)))
		exit(0);
	time(&t);
	cr_time = ctime(&t);
	while (str[x] && str[x] != ' ')
		++x;
	if (ft_strstr(cr_time + ft_strlen(cr_time) - 4, str + ft_strlen(str) - 4))
		while (str[x] && tmp < 2)
		{
			ft_putchar(str[x++]);
			if (str[x] == ':')
				++tmp;
		}
	else
		aff_year(str, x, tmp);
}

void	aff_type(struct s_data *data)
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
