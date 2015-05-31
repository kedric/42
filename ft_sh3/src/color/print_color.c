/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 10:51:35 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/02 14:44:48 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "color.h"

void	ft_putstr_c(char *s, int c)
{
	ft_putstr("\033[0m");
	if (c == RED)
		ft_putstr("\033[31m");
	if (c == GREEN)
		ft_putstr("\033[32m");
	if (c == YELLOW)
		ft_putstr("\033[33m");
	if (c == BLUE)
		ft_putstr("\033[34m");
	if (c == MAGENTA)
		ft_putstr("\033[35m");
	if (c == CYAN)
		ft_putstr("\033[36m");
	if (c == WHITE)
		ft_putstr("\033[37m");
	ft_putstr(s);
	ft_putstr("\033[0m");
}

