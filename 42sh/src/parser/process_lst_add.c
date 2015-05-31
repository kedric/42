/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lst_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:40:31 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/04 18:09:48 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_process				*process_lst_add(t_process *lst, char *str)
{
	t_process			*new_process;
	t_process			*current;

	if (!(new_process = create_process(str)))
		return (NULL);
	if (!lst)
		return (new_process);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new_process;
	new_process->prev = current;
	return (lst);
}
