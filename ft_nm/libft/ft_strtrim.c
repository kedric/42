/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char			*ft_strtrim(char const *s)
{
	char	*ret;
	char	*tmp;
	size_t	size;

	size = ft_strlen((char *)s);
	if (size == 0)
	{
		ret = (char *)malloc(1 * sizeof(char));
		ret = '\0';
		return (ret);
	}
	while (*s == '\t' || *s == '\n' || *s == ' ')
		s++;
	size = ft_strlen((char *)s);
	tmp = (char *)s + size - 1;
	while (tmp > s && (*tmp == ' ' || *tmp == '\t' || *tmp == '\n'))
		tmp--;
	size = (tmp - s) + 1;
	ret = (char *)malloc((size + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret = ft_strncpy(ret, s, size);
	*(ret + size) = '\0';
	return (ret);
}
