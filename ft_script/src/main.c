/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 09:30:02 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 13:37:13 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int		open_file(t_opt *opt)
{
	int fd;

	if (opt->opt_a == 0)
	{
		if ((fd = open(opt->file_name, O_WRONLY | O_CREAT
						| O_TRUNC, 00644)) < 0)
		{
			ft_puterr("fail to open file");
			reset_exit(opt);
		}
	}
	else
	{
		if ((fd = open(opt->file_name, O_WRONLY | O_CREAT
						| O_APPEND, 00644)) < 0)
		{
			ft_puterr("fail to open file");
			reset_exit(opt);
		}
	}
	return (fd);
}

void	init_struct(t_opt *opt)
{
	int i;

	i = 0;
	opt->opt_a = 0;
	opt->opt_q = 0;
	opt->cmd[0] = NULL;
	opt->file_name = NULL;
	while (opt->env[i] && ft_strncmp(opt->env[i], "SHELL", 5))
		i++;
	opt->shell = (opt->env[i] == NULL) ? "/bin/sh" : opt->env[i] + 6;
	ioctl(0, TIOCGETA, &opt->orig);
	ioctl(0, TIOCGWINSZ, &opt->winsize);
	ft_bzero(opt->cmd_av, 4096);
}

int		creat_cmd(char **av, int i, t_opt *opt)
{
	int		fd;
	char	cmd[4096];

	ft_bzero(cmd, 4096);
	fd = open("/tmp/.tmp_file", O_RDWR | O_CREAT, 00777);
	while (av[i])
	{
		ft_strcat(cmd, av[i++]);
		ft_strcat(cmd, " ");
	}
	ft_strcat(cmd, "\n");
	ft_putendl_fd(cmd, fd);
	opt->cmd[0] = opt->shell;
	opt->cmd[1] = "/tmp/.tmp_file";
	opt->cmd[2] = NULL;
	close(fd);
	return (i - 1);
}

void	parse_arg(int ac, char **av, t_opt *opt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (av[++i])
	{
		if (av[i][0] == '-' && opt->file_name == NULL)
		{
			while (av[i][++j])
			{
				opt->opt_a = (av[i][j] == 'a') ? 1 : opt->opt_a;
				opt->opt_q = (av[i][j] == 'q') ? 1 : opt->opt_q;
			}
			j = 0;
		}
		else
		{
			if (opt->file_name == NULL)
				opt->file_name = av[i];
			else
				i = creat_cmd(av, i, opt);
		}
	}
}

int		main(int ac, char **av, char **env)
{
	t_opt	opt;
	int		fd;

	opt.env = env;
	init_struct(&opt);
	parse_arg(ac, av, &opt);
	opt.file_name = (opt.file_name == NULL) ? "typescript" : opt.file_name;
	if (open_ptym(&opt))
		return (-1);
	fork_pty(&opt);
	set_master();
	opt.fd_file = open_file(&opt);
	if (opt.opt_q == 0)
		say_started(&opt);
	if (access(opt.shell, X_OK))
	{
		ft_putstr_fd("script: : No such file or directory\n", opt.fd_file);
		ft_putstr_fd("script: : No such file or directory\n", 1);
		reset_exit(&opt);
	}
	while (1)
		wait_fd(&opt);
}
