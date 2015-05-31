/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 17:54:09 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/19 07:38:52 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s != 0 && n > 0)
	{
		while (i < n)
		{
			*((char *)s + i) = '\0';
			i++;
		}
	}
}

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s2)
	{
		while (i < n)
		{
			*((unsigned char *)s1 + i) = *((unsigned char *)s2 + i);
			i++;
		}
		return (s1);
	}
	else
		return (0);
}
