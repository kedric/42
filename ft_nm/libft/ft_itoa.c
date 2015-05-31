/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:19 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:19 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <string.h>

char		*ft_itoa(int n)
{
	char	*res;
	char	*save;
	int		neg;

	if ((res = (char *)malloc(sizeof(char) * 13)) == NULL)
		return (NULL);
	neg = 0;
	save = res;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && (n = -n))
		neg = -1;
	while (n > 0)
	{
		*res++ = ((n % 10) + '0');
		n = n / 10;
	}
	if (neg)
		*res++ = '-';
	*res = '\0';
	res = ft_strrev(save);
	return (res);
}
