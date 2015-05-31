/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 15:52:11 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/18 14:36:45 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <stdio.h>

int		func_ls(int cs)
{
	DIR				*dirp;
	struct dirent	*dir;
	char			ret_ls[4096];

	dirp = opendir(".");
	ft_bzero(ret_ls, 4096);
	while ((dir = readdir(dirp)))
	{
		ft_strcat(ret_ls, dir->d_name);
		ft_strcat(ret_ls, "\n");
	}
	ft_strcat(ret_ls, "SUCCESS");
	send(cs, ret_ls, ft_strlen(ret_ls), 0);
	closedir(dirp);
	return (1);
}

int		func_cd(char *buff, int cs, char *pwd)
{
	char buf[4096];
	char *tmp;
	char *tmp2;

	ft_bzero(buf, 4096);
	tmp = ft_strtrim(buff + 3);
	if (chdir(tmp) != -1)
	{
		if (ft_strlen(getcwd(buf, 4096)) >= ft_strlen(pwd))
			send(cs, "SUCCESS", 7, 0);
		else
		{
			chdir(pwd);
			send(cs, "ERROR you dont have right", 25, 0);
		}
	}
	else
		send(cs, "ERROR you dont have right", 25, 0);
	free(tmp);
	return (1);
}

int		func_pwd(int cs)
{
	char buff[4096];

	send(cs, getcwd(buff, 4096), ft_strlen(getcwd(buff, 4096)), 0);
	return (1);
}
