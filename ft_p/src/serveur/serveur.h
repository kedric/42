/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 16:02:55 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/18 14:43:04 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

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

int				func_ls(int cs);
int				func_pwd(int cs);
int				func_cd(char *buff, int cs, char *pwd);
int				sfile_ftp(char *buff, int cs);

#endif
