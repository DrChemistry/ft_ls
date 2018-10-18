/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:39:30 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/19 13:57:53 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	fu(char *save, char **line, int x, int b)
{
	if (!(line[0] = malloc(sizeof(char) * x + 1)))
		return (-1);
	line[0][x] = '\0';
	b = x;
	while (--x >= 0)
		line[0][x] = save[x];
	while (save[b] && save[b + 1])
		save[++x] = save[++b];
	save[++x] = '\0';
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save;
	char		buff[BUFF_SIZE + 1];
	int			x;
	char		*tst;

	if (fd < 0 || line == NULL || (!save && !(save = ft_strnew(BUFF_SIZE + 1))))
		return (-1);
	if (save[ft_findchar(save, '\n')] == '\n')
		return (fu(save, line, ft_findchar(save, '\n'), 0) == -1 ? -1 : 1);
	while ((x = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[x] = '\0';
		tst = save;
		if (!(save = ft_strjoin(save, buff)))
			return (-1);
		free(tst);
		if (save[ft_findchar(save, '\n')] == '\n')
			return (fu(save, line, ft_findchar(save, '\n'), x) == -1 ? -1 : 1);
	}
	if (x == 0 && (save[ft_findchar(save, '\n')] == '\n'
		|| ft_findchar(save, '\n') > 0))
		return (fu(save, line, ft_findchar(save, '\n'), 0) == -1 ? -1 : 1);
	return (x);
}
