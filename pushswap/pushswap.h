/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 08:13:05 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/29 16:37:29 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct		s_list
{
	int				value;
	struct s_list	*next;

}					t_list;

void	ft_print_lst(t_list *lst);
t_list	*ft_list_insert(t_list *lst, t_list *insert);
t_list	*ft_list_new(int value);
void	ft_swap(t_list **lst);
void	ft_placeend(t_list **lst);
void	ft_placestart(t_list **lst);
void	ft_changelist(t_list **src, t_list **dest);
int		ft_srch_min(t_list **lsta, t_list *lstab, int d);
void	ft_putact(t_list *lsta, t_list *lstb, char *act, int d);

#endif /*!PUSHSWAP_H*/
