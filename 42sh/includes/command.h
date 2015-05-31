/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:07:37 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:45:58 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2

# include "struct.h"

void		launch_process (t_process *p, t_gen *gen);
void		launch_job (t_job *j, t_gen *gen);
void		ft_close_pipe(t_process *p);
void		ft_fork(t_process *p, t_gen *gen);
void		ft_command(t_command *com, t_gen *gen);
t_job		*get_job_next(t_job *job, int success);
void		check_redirection(t_process *p, t_gen *envp);
int			ft_run_builtin(t_process *p, t_gen *env);
int			ft_checkbuiltin(t_process *p, t_gen *gen);

#endif
