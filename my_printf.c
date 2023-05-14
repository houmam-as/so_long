/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:55:43 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/21 01:42:09 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	digit_nbr(int m)
{
	long	n;
	int		i;

	n = m;
	i = 0;
	if (m == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int m)
{
	long	n;

	n = m;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (digit_nbr(m));
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_percent(const char *s, int i, va_list valist)
{
	int	sum;

	sum = 0;
	if (s[i] == '%')
		sum += ft_putchar('%');
	else if (s[i] == 'd' || s[i] == 'i')
		sum += ft_putnbr(va_arg(valist, int));
	else if (s[i] == 'c')
		sum += ft_putchar(va_arg(valist, int));
	else if (s[i] == 's')
		sum += ft_putstr(va_arg(valist, char *));
	return (sum);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		sum;
	va_list	args;

	va_start(args, s);
	i = 0;
	sum = 0;
	while (s[i])
	{
		if (s[i] == '%')
			sum += ft_percent(s, ++i, args);
		else
			sum += write (1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (sum);
}
