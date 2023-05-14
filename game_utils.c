/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:41:31 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/21 01:42:22 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nbr_l(int n)
{
	long	num;
	int		i;

	num = n;
	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		nl;
	char	*p;

	nb = n;
	nl = nbr_l(nb);
	p = malloc (nl * sizeof(char) + 1);
	if (!p)
		return (NULL);
	if (n == 0)
		p[0] = 48;
	else if (nb < 0)
	{
		p[0] = 45;
		nb *= -1;
	}
	while (nb)
	{
		p[nl - 1] = nb % 10 + 48;
		nb /= 10;
		nl--;
	}
	p[nbr_l(n)] = 0;
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 || *s2)
	{
		if (n == 0)
			return (0);
		if ((unsigned char)*s1 > (unsigned char)*s2)
			return (1);
		if ((unsigned char)*s1 < (unsigned char)*s2)
			return (-1);
		if (*s1 == 0 || *s2 == 0)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	int				strsiz;

	str = (unsigned char *)s;
	strsiz = ft_strlen(s);
	if ((unsigned char)c == 0)
		return ((char *)str + strsiz);
	else if (strsiz == 0)
		return (NULL);
	while (strsiz >= 0)
	{
		if (*(str + strsiz) == (unsigned char)c)
			return ((char *)str + strsiz);
		strsiz--;
	}
	return (NULL);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
