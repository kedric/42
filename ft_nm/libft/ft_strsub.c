/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*save_ret;
	char	*save;
	size_t	size;

	if (!s)
		return (NULL);
	save = (char *)s;
	size = ft_strlen((char *)s);
	if (start < 1 && len < 1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size - len));
	if (ret == NULL)
		return (NULL);
	save_ret = ret;
	while (start-- && *save)
		save++;
	while (len-- && *save)
	{
		*ret = *save;
		ret++;
		save++;
	}
	*ret = '\0';
	return (save_ret);
}
