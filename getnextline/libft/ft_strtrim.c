/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 13:52:10 by jmancero          #+#    #+#             */
/*   Updated: 2013/11/30 22:26:26 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	int			i;
	int			str_len;
	int			j;

	i = (j = 0);
	if (!s)
		return (NULL);
	str = ft_memalloc(ft_strlen((char *)s));
	if (!str)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		j += 1 + 0 * (i += 1);
	str = ft_strcpy(str, s + i);
	str_len = ft_strlen(str);
	i = 1;
	while (str[str_len - i] == ' ' || str[str_len - i] == '\n'\
		|| str[str_len - i] == '\t')
	{
		str[str_len - i] = '\0';
		j += 1 + 0 * (i += 1);
	}
	if (j != 0)
		return (str);
	return (str);
}
