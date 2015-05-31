/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 08:45:10 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/21 15:29:43 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	ft_nbrinchar(int n, char *str, int i)
{
	if (n >= 0)
	{
		if (n >= 10)
		{
			ft_nbrinchar(n / 10, str, i + 1);
			str[ft_strlen(str)] = n % 10 + '0';
		}
		else
		{
			str[ft_strlen(str)] = '0' + n;
		}
	}
	else
	{
		str[0] = '-';
		ft_nbrinchar(-n, str, i + 1);
	}
}

char		*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 13);
	if (str && n <= 2147483647 && n >= -2147483647)
	{
		ft_bzero(str, 11);
		ft_nbrinchar(n, str, 0);
	}
	if (n == -2147483648)
	{
		ft_bzero(str, 11);
		ft_nbrinchar(n + 1, str, 0);
		str[10] = '8';
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
