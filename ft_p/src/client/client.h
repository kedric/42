/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 17:35:59 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/18 14:29:30 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <dirent.h>
# include <sys/types.h>

typedef struct	s_pkg
{
	int			brk;
	char		buff[4096];
	char		name[1024];
	int			len;
}				t_pkg;

int				file_ftp(char *buff, int cs);

#endif
