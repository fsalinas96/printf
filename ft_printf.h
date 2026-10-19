/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:57:57 by fsalinas          #+#    #+#             */
/*   Updated: 2026/10/19 14:11:26 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_typecheck(char s, va_list args);
int	ft_printf(const char *s, ...);
int	ft_putnbr(long nb);
int	ft_putnbrhex(unsigned long nb);
int	ft_putnbruphex(unsigned long nb);
int	ft_putchar(int c);
int	ft_putstr(char *str);

#endif