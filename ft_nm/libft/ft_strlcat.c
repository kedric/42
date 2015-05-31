/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*tmpdst;
	const char		*tmpsrc;
	size_t			len;
	size_t			n;

	n = size;
	tmpdst = dst;
	tmpsrc = src;
	while (*tmpdst && n--)
		tmpdst++;
	len = tmpdst - dst;
	n = size - len;
	if (n <= 0)
		return (len + ft_strlen((char *)tmpsrc));
	while (*tmpsrc)
	{
		if (n != 1)
		{
			*tmpdst++ = *tmpsrc;
			n--;
		}
		tmpsrc++;
	}
	*tmpdst = '\0';
	return (len + (tmpsrc - src));
}
