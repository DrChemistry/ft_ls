/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:17:41 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/10/26 13:57:28 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int		ft_exit(t_comm *data)
{
	ft_quit("exit12", 1, data);
	return (0);
}

void	ft_quit(char *msg, int outp, t_comm *comm)
{
	int		x;
	t_comm	*tmp;

	delete_comms(comm);
	ft_putendl_fd(msg, outp);
	while (1)
	;
	exit(1);
}
