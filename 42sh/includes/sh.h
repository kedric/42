/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 09:45:39 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 19:09:32 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# define BUFF_SIZE 4096
# include <termios.h>
# include <term.h>
# include "struct.h"
# include "term_caps.h"
# include "libft.h"

void	print_key(char *key);

void	affiche_prompte(t_gen *gen);
void	ft_rappel(void);

void	destroy_gen(void);
t_gen	*recup_gen(void);
void	init_env(char **env);
char	*ft_getenv(char *to_search);
char	**creat_env();

void	parse_ps1(t_ps1 *ps1);
int		get_on_ps1(char c, t_ps1 *ps1);
char	*ft_getdir(int opt);
char	*ft_gettime(int format);
char	*add_char(char *str, char c);

void	init_term();
void	close_term();
void	tc_stomp(char *buff, t_gen *gen);
char	*key_to_str(int a, int b, int c, int d);

t_hist	*add_element(t_hist *hist);
t_hist	*save_hist(t_hist *hist);

void	ft_parse_and_exec(char *line, t_gen *gen);
void	updat_prompt(t_ps1 *ps1);
void	free_split(char ***to_free);
void	erase_list(t_builtin **list);
void	ft_freetmpenv(t_gen *tmpenv);

#endif
