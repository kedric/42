/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:14:14 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 18:13:41 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "struct.h"
# include "parser.h"

int			ft_strstrlen(char **s);
int			ft_found(char *s, t_gen *env);

t_builtin	**init_listbuiltin();

void		ft_builtin(t_process *p, t_gen *env);
void		erase_list(t_builtin **builtin);
void		ft_freetmpenv(t_gen *env);
void		ft_env(t_process *p, t_gen *env);
t_gen		*ft_setenv(const char *n, const char *v, int ow, t_gen *env);
t_gen		*ft_putenv(const char *n, const char *v, t_gen *env);
t_gen		*ft_unsetenv(const char *n, t_gen *env);
char		*ft_trim(char *s);
char		*ft_glue(char **s);
void		ft_pwd(t_gen *env, t_process *p);
void		ft_echo(t_process *p);
t_gen		*ft_cd(char *path, t_gen *env);
void		ft_help(t_process *p, t_builtin **builtin);
void		free_split(char ***to_free);

#endif
