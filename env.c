/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:55:38 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/09/24 09:55:39 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

int			ft_setenv(t_comm *data, t_env *env)
{
	printf("test3\n");
	return (SUCCESS);
}

int			ft_unsetenv(t_comm *data, t_env *env)
{
	printf("test4\n");
	return (SUCCESS);
}

int			ft_env(t_comm *data, t_env *env)
{
	int x;

	x = 0;
	while (env->env[x])
	{
		ft_putstr(env->env[x++]);
		ft_putchar('\n');
	}
	return (SUCCESS);
}
