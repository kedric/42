/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:46:15 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/24 19:26:44 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

t_cmd	*parse_cmd(char **tmpstr, t_cmd *start)
{
	t_cmd	*tmp_mv;
	t_cmd	*tmp;
	int		i;

	i = 0;
	while (tmpstr[i])
	{
		tmp = (t_cmd *)malloc(sizeof(t_cmd));
		tmp->value = tmpstr[i];
		tmp->name = NULL;
		tmp->sfd = 0;
		tmp->next = NULL;
		tmp->file = NULL;
		if (start != NULL)
		{
			tmp_mv->next = tmp;
			tmp_mv = tmp_mv->next;
		}
		tmp_mv = (start == NULL) ? (start = tmp) : tmp_mv;
		i++;
	}
	return (start);
}

int		search_endstr(t_cmd *start, int i)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;
	char	*str_tmp;

	tmp = start;
	while (tmp->value[i] != '"' || tmp->value[i - 1] == '\\')
	{
		if (tmp->value[i++] == '\0')
		{
			if (tmp->next == NULL)
				return (-1);
			str_tmp = ft_strjoin(tmp->value, ";");
			free(tmp->value);
			tmp->value = str_tmp;
			str_tmp = ft_strjoin(tmp->value, tmp->next->value);
			free(tmp->value);
			tmp->value = str_tmp;
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			if (tmp2->next == NULL)
				tmp->next = NULL;
			free(tmp2);
		}
	}
	return (i + 1);
}

t_cmd	*clean_cmd(t_cmd *start)
{
	t_cmd	*tmp;
	char	*cmd;
	int		i;

	i = 0;
	tmp = start;
	while (tmp)
	{
		i = 0;
		while (tmp->value[i])
		{
			if (tmp->value[i] == '"' && tmp->value[i - 1] != '\\')
			{
				if ((i = search_endstr(tmp, i + 1)) == -1)
					return (NULL);
			}
			i++;
		}
		cmd = ft_strtrim(tmp->value);
		free(tmp->value);
		tmp->value = ft_strdelc(cmd, '"');
		free(cmd);
		tmp = tmp->next;
	}
	return (start);
}

void	parse_name(t_cmd *cmd)
{
	char	**tmp;

	while (cmd)
	{
		tmp = ft_strsplit(cmd->value, ' ');
		cmd->name = tmp[0];
		cmd = cmd->next;
		free(tmp);
	}
}

int		assign_file_out(t_cmd *cmd)
{
	char	**file;

	if (ft_strstr(cmd->value, ">>") == NULL)
		cmd->sfd = 2;
	else
		cmd->sfd = 6;
	file = ft_strsplit(cmd->value, '>');
	cmd->value = file[0];
	if (file[1])
		cmd->file = ft_strtrim(file[1]);
	else
		return (-1);
	free(file);
	file = ft_strsplit(cmd->value, ' ');
	cmd->name = ft_strtrim(file[0]);
	free(file);
	return (0);
}
