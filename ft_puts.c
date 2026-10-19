/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:58:42 by fsalinas          #+#    #+#             */
/*   Updated: 2026/10/19 14:00:41 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	char	c;
	int		i;

	i = 0;
	if (nb < 0)
	{
		nb = (nb * -1);
		write (1, "-", 1);
		i++;
	}
	if (nb >= 10)
	{
		i = i + ft_putnbr(nb / 10);
	}
	i++;
	c = (nb % 10) + '0';
	write (1, &c, 1);
	return (i);
}

int	ft_putnbrhex(unsigned long nb)
{
	char	c;
	int		i;

	i = 0;
	if (nb >= 16)
	{
		i = i + ft_putnbrhex(nb / 16);
	}
	i++;
	if (nb % 16 >= 10 && nb % 16 <= 15)
		c = (nb % 16) + 'a' - 10;
	else
		c = (nb % 16) + '0';
	write (1, &c, 1);
	return (i);
}

int	ft_putnbruphex(unsigned long nb)
{
	char	c;
	int		i;

	i = 0;
	if (nb >= 16)
		i = i + ft_putnbruphex(nb / 16);
	i++;
	if (nb % 16 >= 10 && nb % 16 <= 15)
		c = (nb % 16) + 'A' - 10;
	else
		c = (nb % 16) + '0';
	write (1, &c, 1);
	return (i);
}

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}
