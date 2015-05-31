/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:40:47 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/11 16:40:01 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int		ft_nbword(char const *s, char c)
{
	unsigned int		nbword;

	nbword = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		nbword = (*s ? nbword + 1 : nbword);
		while (*s && *s != c)
			s++;
	}
	return (nbword);
}

static unsigned int		ft_nextwordlen(char const *s, unsigned int i, char c)
{
	unsigned int		len;

	len = 0;
	while (s[i + len] != '\0' && s[i + len] != c)
		len++;
	return (len);
}

char					**ft_strsplit(char const *s, char c)
{
	char				**ret;
	unsigned int		i;
	unsigned int		nbword;
	unsigned int		j;
	unsigned int		nextword;

	nbword = ft_nbword(s, c);
	nbword = (nbword == 0 ? 1 : nbword);
	i = 0 * (j = 0);
	ret = (char **)malloc((nbword + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (i < nbword)
	{
		while (s[j] == c)
			j++;
		nextword = ft_nextwordlen(s, j, c);
		nextword = (nextword == 0 ? 1 : nextword);
		if ((ret[i] = ft_strsub(s, j, nextword)) == NULL)
			return (NULL);
		j += nextword;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void				ft_freesplit(char **s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		free(s[i]);
	free(s);
}

char				**ft_splitendfree(char *s, char c)
{
	char **ret;

	ret = ft_strsplit(s, c);
	free(s);
	return (ret);
}

