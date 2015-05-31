/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 10:08:30 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/25 11:35:21 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
void ft_printlst(t_plt *plt)
{
	while(plt)
	{
		ft_putnbr(plt->pos);
		ft_putstr(plt->value);
		ft_putstr("\n");
		plt = plt->next;
	}
}

int	main()
{
	t_plt *plt;

	plt = parse_enter();
	ft_printlst(plt);
	return(0);
}
