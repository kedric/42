/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 14:49:36 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/07 08:04:52 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_hist	*add_ellement_hist(t_hist *hist)
{
	t_hist	*tmp;

	tmp = (t_hist *)malloc(sizeof(t_hist));
	if (tmp == NULL)
		ft_puterr("fail malloc");
	tmp->pose_cursor = 0;
	tmp->len = 0;
	tmp->exec = 1;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (hist == NULL)
		return (tmp);
	else
	{
		while (hist->next)
			hist = hist->next;
		tmp->prev = hist;
		hist->next = tmp;
	}
	return (tmp);
}

t_hist	*add_or_clean(t_hist *hist)
{
	if (hist == NULL)
		return (add_ellement_hist(hist));
	while (hist->next)
		hist = hist->next;
	if (hist->exec == 1 && hist->len == 0)
	{
		ft_bzero(hist->value, BUFF_SIZE);
		ft_bzero(hist->buff, BUFF_SIZE);
		hist->exec = 1;
		hist->modif = 1;
		hist->pose_cursor = -1;
		hist->len = -1;
		return (hist);
	}
	else
		return (add_ellement_hist(hist));
}

void	restor_hist(t_hist *hist)
{
	while (hist)
	{
		if (hist->modif == 1)
		{
			ft_strcpy(hist->buff, hist->value);
			hist->len = (int)ft_strlen(hist->value);
			hist->pose_cursor = hist->len;
			hist->modif = 0;
		}
	hist = hist->prev;
	}
}

int		clean_hist(t_hist *hist)
{
	t_hist	*tmp;

	if (hist == NULL)
		return (1) ;
	tmp = hist;
	while (hist->next)
		hist = hist->next;
	if (hist->exec == 0 && hist->next == NULL)
	{
		ft_strcpy(hist->value, tmp->buff);
		ft_strcpy(hist->buff, hist->value);
		hist->exec = 1;
		hist->len = ft_strlen(hist->value);
		hist->pose_cursor = hist->len;
	}
	restor_hist(hist);
	return (0);
}
