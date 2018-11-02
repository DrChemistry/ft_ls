/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:00:05 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/11/02 13:01:06 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

void	print_prompt(t_comm *comm)
{
	char	*buf;
	int		x;

	if (!(buf = malloc(sizeof(char) * 128)))
		ft_quit("bash: erreur allocution memoir", 2, comm);
	x = 1;
	while (!(getcwd(buf, 128 * x)))
	{
		if (!(buf = malloc(sizeof(char) * (128 * x))))
			ft_quit("bash: erreur allocution memoir", 2, comm);
		++x;
	}
	ft_putstr(GREEN);
	ft_putstr(buf);
	ft_putstr(RESET);
	write(1, " $>", 3);
}
