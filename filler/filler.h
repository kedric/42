/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 10:08:19 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/25 11:11:04 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BUFF_SIZE 4096
# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct		s_plt
{
	char			*value;
	int				pos;
	struct s_plt	*next;

}					t_plt;

t_plt	*parse_enter(void);

#endif /*FILLER_H*/
