/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:19 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:19 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		minus;
	int		res;

	res = 0;
	minus = 1;
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n'
				|| *str == '\r' || *str == '\f' || *str == '\v')
			str++;
		if (*str == '-' && str++)
			minus = -1;
		else if (*str == '+' && str++)
			minus = 1;
		while (*str >= '0' && *str <= '9')
			res = res * 10 + (*str++ - '0');
	}
	return (minus * res);
}
