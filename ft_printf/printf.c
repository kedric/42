/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 12:33:09 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/18 14:01:45 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

void ft_putunbr(unsigned int x)
{
}

void	ft_printf_select(va_list args, char *str)
{
		if (str[1] == 's')
				ft_putstr(va_arg(args, char *));
			else if (str[1] == 'd' || str[1] == 'i')
				ft_putnbr(va_arg(args, int));
			else if (str[1] == 'c')
				ft_putchar((char)va_arg(args, int));
			else if (str[1] == 'x')
				ft_puthexa(va_arg(args, unsigned int), 0);
			else if (str[1] == 'X')
				ft_puthexa(va_arg(args, unsigned int), 1);
			else if (str[1] == 'u')
				ft_putunbr(va_arg(args, unsigned int));
			else
			ft_putchar(str[1]);
}

void	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	while (*str)
    {
		if (*str == '%')
        {
			ft_printf_select(args, str);
			str++;
        }
		else
			ft_putchar(*str);
		str++;
    }
	va_end(args);
}


