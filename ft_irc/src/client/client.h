/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 11:58:26 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/25 18:56:44 by jmancero         ###   ########.fr       */
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
# include <stdio.h>
# include <sys/select.h>

# define BUFF_SIZE 4096
# define XV(err,res,str)	(x_void(err, res, str, e_i(__FILE__, __LINE__)))
# define X(err,res,str)		(x_int(err, res, str, e_i(__FILE__, __LINE__)))

typedef struct	s_env
{
	int		port;
	char	*addr;
	int		sock;
	int		channel;
	char	*pseudo;
	int		ret;
	int		aff_prompt;
	char	buff_read[BUFF_SIZE];
	char	buff_write[BUFF_SIZE];
	fd_set	fd_read;
	fd_set	fd_write;
}				t_env;

/*
** error
*/
typedef struct	s_errror
{
	char		*file;
	int			line;
}				t_error;

t_error			e_i(char *file, int line);
void			*x_void(void *err, void *res, char *str, t_error e);
int				x_int(int err, int res, char *str, t_error e);

void			fct_read(t_env *env);
void			fct_write(t_env *env);

#endif
