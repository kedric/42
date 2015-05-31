/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:11:41 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/01 16:26:30 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr(int n)
{
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n >= 0)
		{
			if (n >= 10)
			{
				ft_putnbr(n / 10);
				ft_putchar(n % 10 + '0');
			}
			else
			{
				ft_putchar('0' + n);
			}
		}
		else
		{
			ft_putchar('-');
			ft_putnbr(-n);
		}
	}
	else if (n == INT_MIN)
		ft_putstr("-2147483648");
}
