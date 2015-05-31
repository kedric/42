/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:18:32 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/11 16:29:13 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	ft_compn(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s2[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	match;
	size_t	size_s2;

	i = 0;
	size_s2 = ft_strlen((char *)s2);
	match = 0;
	if (!*s2)
	{
		return ((char *)s1);
	}
	while (s1[i] != '\0' && n > i)
	{
		if (s1[i] == s2[0])
		{
			match = ft_compn(((char *)s1 + i), ((char *)s2));
			if (match == 1 && i + size_s2 <= n)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}

