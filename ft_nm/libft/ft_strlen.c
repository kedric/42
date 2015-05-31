/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(char const *s)
{
	char	*save;

	if (s)
	{
		save = (char *)s;
		while (*save)
			++save;
		return (save - s);
	}
	return (0);
}
