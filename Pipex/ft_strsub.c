/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 10:21:39 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/31 10:54:23 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if ((ret = (char *) malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	++size;
	while (size-- > 0)
		ret[size] = '\0';
	return (ret);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		++i;
	}
	return (ret);
}
