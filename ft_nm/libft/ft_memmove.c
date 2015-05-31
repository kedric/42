/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:19 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:19 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	char			*tmp;

	if (s1 && s2)
	{
		if ((tmp = (char *)malloc(n * sizeof(char))) == NULL)
			return (NULL);
		ft_memcpy(tmp, s2, n);
		ft_memcpy(s1, tmp, n);
		free(tmp);
		return (s1);
	}
	return (NULL);
}
