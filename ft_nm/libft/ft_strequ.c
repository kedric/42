/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strequ(char const *s1, char const *s2)
{
	char	*s12;
	char	*s22;

	if (s1 && s2)
	{
		s12 = (char *)s1;
		s22 = (char *)s2;
		if (ft_strlen(s12) < ft_strlen(s22))
			return (0);
		while (*s12)
		{
			if (*s12 != *s22)
				return (0);
			s12++;
			s22++;
		}
		return (1);
	}
	return (0);
}
