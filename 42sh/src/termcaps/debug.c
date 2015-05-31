/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:13:48 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:13:50 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void print_key(char *key)
{
	ft_putstr("touche appuyer : [");
	ft_putnbr((int)key[0]);
	ft_putstr("] [");
	ft_putnbr((int)key[1]);
	ft_putstr("] [");
	ft_putnbr((int)key[2]);
	ft_putstr("] [");
	ft_putnbr((int)key[3]);
	ft_putstr("];\n");
}
