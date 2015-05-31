/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:22:49 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:22:55 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"
#include <sys/time.h>

char		*add_char(char *str, char c)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	i = 0;
	if (str)
		while (str[i])
		{
			tmp[i] = str[i];
			i++;
		}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	if (str != NULL)
		free(str);
	return (tmp);
}

char		*ft_gettime(int format)
{
	struct timeval	tv;
	struct timezone	tz;
	char			*t[5];
	int				i[2];

	i[0] = 3;
	t[4] = NULL;
	gettimeofday(&tv, &tz);
	t[0] = ft_itoa(tv.tv_sec % 60);
	t[1] = ft_itoa((tv.tv_sec / 60) % 60);
	t[2] = ft_itoa((tv.tv_sec / 60) / 60 % 24 + 1);
	t[3] = NULL;
	while (--i[0] >= format)
	{
		if (ft_strlen(t[i[0]]) == 2)
			t[4] = ft_joinfree(t[4], t[i[0]], 3);
		else
		{
			t[4] = add_char(t[4], '0');
			t[4] = add_char(t[4], t[i[0]][0]);
		}
		t[4] = ft_joinfree(t[4], ":", 1);
	}
	t[4][ft_strlen(t[4]) - 1] = 0;
	return (t[4]);
}

char		*ft_getdir(int opt)
{
	char	*tmp;
	char	**tmp2;
	int		i;

	tmp = NULL;
	i = 0;
	if (opt == 0)
	{
		tmp2 = ft_strsplit(ft_getenv("PWD="), '/');
		while (tmp2[i + 1])
			i++;
		tmp = ft_joinfree("/", ft_strdup(tmp2[i]), 2);
		ft_freesplit(tmp2);
		return (tmp);
	}
	else
	{
		i = ft_strlen(ft_getenv("HOME="));
		if (!ft_strncmp(ft_getenv("PWD="), ft_getenv("HOME="), i))
			tmp = ft_joinfree("~", ft_strdup(ft_getenv("PWD=") + i), 2);
		else
			tmp = ft_strdup(ft_getenv("PWD="));
	}
	return (tmp);
}

int			get_on_ps1(char c, t_ps1 *ps1)
{
	char	*op;
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	op = "nt*Dd~012345\0";
	while (op[i] && op[i] != c)
		i++;
	if (op[i] == '\0')
		return (0);
	tmp = (i == 0) ? ft_strdup(ft_getenv("USER=")) : tmp;
	tmp = (i == 1) ? ft_gettime(1) : tmp;
	tmp = (i == 2) ? ft_gettime(0) : tmp;
	tmp = (i == 3) ? ft_strdup(ft_getenv("PWD=")) : tmp;
	tmp = (i == 4) ? ft_getdir(1) : tmp;
	tmp = (i == 5) ? ft_getdir(1) : tmp;
	tmp = (i == 6) ? ft_strdup("\033[0m") : tmp;
	tmp = (i == 7) ? ft_strdup("\033[31m") : tmp;
	tmp = (i == 8) ? ft_strdup("\033[32m") : tmp;
	tmp = (i == 9) ? ft_strdup("\033[33m") : tmp;
	tmp = (i == 10) ? ft_strdup("\033[34m") : tmp;
	tmp = (i == 11) ? ft_strdup("\033[35m") : tmp;
	ps1->aff = ft_joinfree(ps1->aff, tmp, 3);
	return (1);
}

void		parse_ps1(t_ps1 *ps1)
{
	int	i;

	i = 0;
	ps1->len = 0;
	while (ps1->env[i])
	{
		if (ps1->env[i] == '%' && get_on_ps1(ps1->env[i + 1], ps1))
		{
			if (ps1->env[i] == '%' && ft_isdigit(ps1->env[i + 1]))
			{
				if (ps1->env[i + 1] != '0')
					ps1->len = ps1->len - 1;
				ps1->len = ps1->len - 4;
			}
			i++;
		}
		else
			ps1->aff = add_char(ps1->aff, ps1->env[i]);
		i++;
	}
	ps1->len = ps1->len + ft_strlen(ps1->aff);
	ps1->aff = ft_joinfree(ps1->aff, "\033[0m", 1);
}
