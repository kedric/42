/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strndup(const char *s1, int n)
{
	char	*ptr;
	char	*ret;

	if (s1)
	{
		ptr = (char *)malloc(n * sizeof(char) + 1);
		if (ptr == NULL)
			return (NULL);
		ret = ptr;
		while (n--)
			*ptr++ = *s1++;
		*ptr = '\0';
		return (ret);
	}
	return (NULL);
}
