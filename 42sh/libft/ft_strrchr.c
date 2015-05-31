/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 17:39:15 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/21 17:39:15 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		save;

	i = 0;
	save = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			save = i;
		}
		i++;
	}
	if (c == 0)
	{
		return ((char *)&s[i]);
	}
	else if (save == -1)
	{
		return (NULL);
	}
	return ((char *)&s[save]);
}
