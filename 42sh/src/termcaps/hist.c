/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:13:56 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:13:59 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_hist	*creat_new_hist(void)
{
	t_hist *tmp;

	if (!(tmp = (t_hist *)malloc(sizeof(*tmp))))
		return (NULL);
	tmp->pose_buff = 0;
	tmp->len = 0;
	tmp->modif = 0;
	ft_memset(tmp->value, 0, BUFF_SIZE);
	ft_memset(tmp->buff, 0, BUFF_SIZE);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->number = 1;
	return (tmp);
}

t_hist	*add_element(t_hist *hist)
{
	t_hist	*tmp;
	t_hist	*tmp2;

	tmp = creat_new_hist();
	if (hist == NULL)
		return (tmp);
	else
	{
		tmp2 = hist;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->prev = tmp2;
		tmp->number = tmp2->number + 1;
	}
	return (tmp);
}

void	restor_hist(t_hist *hist)
{
	ft_memcpy(hist->buff, hist->value, BUFF_SIZE);
	hist->modif = 0;
	hist->len = ft_strlen(hist->buff);
	hist->pose_buff = hist->len;
}

void	hist_cp_cmd(t_hist *hist)
{
	t_hist *exec;

	exec = hist;
	while (hist->next)
		hist = hist->next;
	ft_memcpy(hist->value, exec->buff, BUFF_SIZE);
}

t_hist	*save_hist(t_hist *hist)
{
	hist_cp_cmd(hist);
	while (hist->prev)
		hist = hist->prev;
	while (hist->next)
	{
		if (hist->modif)
			restor_hist(hist);
		hist = hist->next;
	}
	restor_hist(hist);
	return (hist);
}
