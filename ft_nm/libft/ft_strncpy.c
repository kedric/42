/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*tmp;

	if (s1 && s2)
	{
		if (!n)
			return (s1);
		tmp = s1;
		while (n--)
			if (*s2)
				*s1++ = *s2++;
			else
				*s1++ = 0;
		return (tmp);
	}
	return (NULL);
}
