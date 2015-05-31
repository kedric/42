/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 22:44:05 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/29 10:13:04 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# define BUFF_SIZE 4096

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_env
{
	char **path;
	char *ps1;
	char *home;
	char *pwd;
	char **environ;
}					t_env;


void	parse_environ(t_env *env);
void	ft_setenv(char **av, t_env *env);
void    ft_unsetenv(char **av, t_env *env);
void    copy_env(t_env *env);
char    *ft_strdelc(const char *s, char c);

#endif /*!FT_SH1_H*/
