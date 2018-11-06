/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:37:20 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/29 09:34:10 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	negmax(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	ft_putchar_fd('1', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('7', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
	ft_putchar_fd('3', fd);
	ft_putchar_fd('6', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		negmax(fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = -nb;
		}
		if (nb >= 10)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + 48, fd);
	}
}
