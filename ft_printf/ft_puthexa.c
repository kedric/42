/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 13:57:19 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/18 14:07:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void ft_puthexa(unsigned int nb, int maj)
{
	unsigned int	nbr;
	unsigned int	i;
	char			*base;

	base = (maj == 0 ? "0123456789abcdef" : "0123456789ABCDEF");
	i = nb % 16;
	nbr = (nb - i) / 16;
	if (nbr)
		ft_puthexa(nbr, maj);
	ft_putchar(base[i]);
}
