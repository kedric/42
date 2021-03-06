/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:50:08 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/07 08:10:11 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	start(void)
{
	char	**av;
	t_env	*env;
	t_term	*term;

	term = recup_term();
	ft_init_signal();
	env = return_env();
	while (1)
	{
		clean_hist(term->hist);
		ft_init_prompte(av, env, 1);
	}
}

void	ft_sh1_relance(t_cmd *cmd, char **av, t_env *env)
{
	if (!ft_strcmp(cmd->value, "exit"))
		exit (0);
	av = ft_strsplit(cmd->value, ' ');
	if (!ft_strcmp(cmd->name, "cd"))
		sh_cd(av, env);
	else if (!ft_strcmp(cmd->name, "setenv"))
		ft_setenv(av, env);
	else if (!ft_strcmp(cmd->name, "unsetenv"))
		ft_unsetenv(av, env);
	else
		sh_execute(cmd->name, av, env);
	free(av);
}

void	ft_init_prompte(char **av, t_env *env, int i)
{
	t_cmd	*cmd;

	cmd = NULL;
	if ((cmd = sh_wait_new_commande(env, cmd)) != NULL)
	{
		if (cmd->value[0] != '\0')
			ft_sh2_relance2(av, env, cmd, i);
	}
	ft_free_cmd(cmd);
}

void	ft_sh2_relance2(char **av, t_env *env, t_cmd *cmd, int i)
{
	static int		save_out;
	static int		save_in;

	if (i == 1)
	{
		save_in = dup(0);
		save_out = dup(1);
	}
	while (cmd)
	{
		if (cmd->sfd == 1)
			ft_sh1_relance(cmd, av, env);
		else if (cmd->sfd == 2)
			outputs_file(cmd->file, av, env, cmd);
		else if (cmd->sfd == 3)
			inputs_file(cmd->file, av, env, cmd);
		else if (cmd->sfd == 4)
			ft_pipe(cmd, av, env);
		else if (cmd->sfd == 5)
			inputs_file(cmd->file, av, env, cmd);
		else if (cmd->sfd == 6)
			outputs_file(cmd->file, av, env, cmd);
		dup2(save_out, 1);
		dup2(save_in, 0);
		cmd = cmd->next;
	}
}
