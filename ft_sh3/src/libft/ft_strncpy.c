/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:09:35 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/21 15:38:30 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2 && n)
	{
		while (i < n && s2[i] != '\0')
		{
			s1[i] = s2[i];
			i++;
		}
		if (ft_strlen(s1) < n || (s2[i] == '\0' && ft_strlen(s2) <= n))
			s1[i] = '\0';
		while (i < n)
		{
			s1[i] = '\0';
			i++;
		}
	}
	return (s1);
}
