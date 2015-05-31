/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 13:49:07 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 15:41:48 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <stdlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

int		handle_64(char *ptr);
void	handle_32(char *ptr);

#endif /* !NM_H */
