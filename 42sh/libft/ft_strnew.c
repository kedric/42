/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 17:39:15 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/21 17:39:15 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*ret;

	if ((ret = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	++size;
	while (size-- > 0)
		ret[size] = '\0';
	return (ret);
}
