/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 14:32:17 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 14:40:09 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char				is_trim(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static unsigned int		get_new_size(const char *s)
{
	unsigned int	size;

	size = 0;
	while (is_trim(*s))
		s++;
	while (*s++)
		size++;
	s--;
	while (is_trim(*s--))
		size--;
	return (size);
}

char					*ft_strtrim(char const *s)
{
	char			*ret;
	unsigned int	size;
	unsigned int	i;

	size = get_new_size(s);
	ft_putstr("Str to trim : [");
	ft_putstr(s);
	ft_putstr("] new_size = ");
	ft_putnbr(size);
	ft_putendl(". ");
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(ret, 0, size + 1);
	while (is_trim(*s))
		s++;
	i = 0;
	while (i < size)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}
