/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 08:33:00 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 15:22:42 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**swap_file_in(char **file)
{
	char	**tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strsplit(file[1], ' ');
	tmp2 = ft_strjoin("< " , tmp[0]);
	tmp3 = ft_strjoin(tmp2 , " ");
	free(tmp2);
	tmp2 = ft_strjoin(tmp3 , file[0]);
	free(tmp3);
	tmp3 = ft_strjoin(tmp2, file[1] + ft_strlen(tmp[0]) + 1);
	free(tmp2);
	free(tmp);
	free(file);
	file = ft_strsplit(tmp3, '<');
	free(tmp3);
	return (file);
}

void	assign_file_in(t_cmd *cmd)
{
	char	**file;

	file = ft_strsplit(cmd->value, '<');
	cmd->sfd = 3;
	if (file[1] != NULL)
		file = swap_file_in(file);
	cmd->value = ft_strtrim(file[0]);
	free(file);
	file = ft_strsplit(cmd->value, ' ');
	cmd->file = file[0];
	cmd->value = ft_strcpy(cmd->value, cmd->value + ft_strlen(file[0]));
	cmd->value = ft_strtrim(cmd->value);
	free(file);
}

int		assign_pipe(t_cmd *cmd)
{
	char	**cmd2;

	cmd->sfd = 4;
	cmd2 = ft_strsplit(cmd->value, '|');
	if (cmd2[1] == NULL)
		return (-1);
	cmd->file = ft_strtrim(cmd->value + ft_strlen(cmd2[0]) + 1);
	cmd->value = cmd2[0];
	free(cmd2);
	cmd2 = ft_strsplit(cmd->value, ' ');
	cmd->name = ft_strtrim(cmd2[0]);
	free(cmd2);
	return (0);
}

int		verif_fd(t_cmd *cmd)
{
	while (cmd)
	{
		if (ft_strchr(cmd->value, '<'))
		{
			assign_file_in(cmd);
		}
		else if (ft_strchr(cmd->value, '|'))
		{
			if (assign_pipe(cmd))
			return (-1);
		}
		else if (ft_strchr(cmd->value, '>'))
		{
			if (assign_file_out(cmd))
			return (-1);
		}
		else
			cmd->sfd = 1;
	cmd = cmd->next;
	}
	return (0);
}

t_cmd	*ft_parse_cmd(char *av)
{
	t_cmd	*cmd;
	char	**tmp;

	cmd = NULL;
	tmp = ft_strsplit(av, ';');
	cmd = parse_cmd(tmp, cmd);
	free(tmp);
	if ((cmd = clean_cmd(cmd)) == NULL)
	{
		ft_puterr("syntax error\n");
		return (NULL);
	}
	if (verif_fd(cmd))
	{
		ft_puterr("syntax error\n");
		return (NULL);
	}
	parse_name(cmd);
	return (cmd);
}
