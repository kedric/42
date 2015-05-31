/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 22:21:05 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/16 12:40:32 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"

size_t		ft_strlen(const char *s)
{
	const char	*str;

	if (s == NULL)
		return (0);
	str = s;
	while (*str)
		str++;
	return (str - s);
}

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_putstr(char const *s)
{
	int	i;

	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}

int			ft_putpoint(long unsigned int n)
{
	if (n < 16)
	{
		if (n < 10)
			return (ft_putstr("0x") + ft_putchar(n + '0'));
		else
			return (ft_putstr("0x") + ft_putchar(n - 10 + 'a'));
	}
	else
	{
		if ((n % 16) < 10)
			return (ft_putpoint(n / 16) + ft_putchar((n % 16) + '0'));
		else
			return (ft_putpoint(n / 16) + ft_putchar((n % 16) - 10 + 'a'));
	}
}

int			ft_putnbr(int n)
{
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n >= 0)
		{
			if (n >= 10)
				return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
			else
				return (ft_putchar('0' + n));
		}
		else
			return (ft_putchar('-') + ft_putnbr(-n));
	}
	else if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	return (0);
}
