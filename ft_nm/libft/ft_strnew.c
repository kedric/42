/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnew(size_t size)
{
	char	*str;

	if (size > 0)
	{
		str = (char *)ft_memalloc((size + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_memset(str, '\0', size + 1);
		return (str);
	}
	return (char *)(NULL);
}
