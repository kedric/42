/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*s12;
	const char	*s22;

	if (s1 && s2)
	{
		s12 = s1;
		s22 = s2;
		while (*s12)
			s12++;
		while (n-- && (*s12++ = *s22++))
			;
		*s12 = '\0';
		return (s1);
	}
	return (NULL);
}
