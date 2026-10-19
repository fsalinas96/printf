/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:58:27 by fsalinas          #+#    #+#             */
/*   Updated: 2026/10/19 14:12:38 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(void *ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_putnbrhex((unsigned long) ptr));
}

int	ft_num(char s, long num)
{
	long	n;
	int		zero;

	zero = '0';
	if (s == 'u')
		n = (unsigned int)num;
	else
		n = (int)num;
	if (!n)
	{
		write(1, &zero, 1);
		return (1);
	}
	zero = ft_putnbr(n);
	return (zero);
}

int	ft_typecheck(char s, va_list args)
{
	int	digits;

	digits = 0;
	if (s == 'c')
		digits = digits + ft_putchar(va_arg(args, int));
	if (s == 's')
		digits = digits + ft_putstr(va_arg(args, char *));
	if (s == 'p')
		digits = digits + ft_p(va_arg(args, void *));
	if (s == 'd' || s == 'i')
		digits = digits + ft_num(s, va_arg(args, int));
	if (s == 'u')
		digits = digits + ft_num(s, va_arg(args, unsigned int));
	if (s == 'x')
		digits = digits + ft_putnbrhex(va_arg(args, unsigned int));
	if (s == 'X')
		digits = digits + ft_putnbruphex(va_arg(args, unsigned int));
	if (s == '%')
	{
		write(1, &s, 1);
		digits++;
	}
	return (digits);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			total = total + ft_typecheck(s[i + 1], args);
			i = i + 2;
		}
		else if (s[i] != '%' && s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
			total = total + 1;
		}
		else if (s[i] == '\0')
			break ;
	}
	va_end (args);
	return (total);
}
