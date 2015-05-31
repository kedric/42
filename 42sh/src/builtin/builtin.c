/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:02:48 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 17:09:11 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_builtin	**init_listbuiltin4(t_builtin **l)
{
	l[6]->help = ft_strcat(l[6]->help, "t specified, the current working dire");
	l[6]->help = ft_strcat(l[6]->help, "ctory will be moved to home.\n");
	l[7] = (t_builtin *)malloc(sizeof(t_builtin));
	l[7]->name = ft_strdup("help");
	l[7]->help = (char *)malloc(sizeof(char) * 85);
	l[7]->help = ft_strcpy(l[7]->help, "USAGE :\nhelp [name] n\nDESCRIPTION :");
	l[7]->help = ft_strcat(l[7]->help, "\nhelp shows informations about built");
	l[7]->help = ft_strcat(l[7]->help, "in commands.\n");
	l[8] = (t_builtin *)malloc(sizeof(t_builtin));
	l[8]->name = ft_strdup("type");
	l[8]->help = (char *)malloc(sizeof(char) * 87);
	l[8]->help = ft_strcpy(l[8]->help, "USAGE :\ntype [command]->n\nDESCRIPTI");
	l[8]->help = ft_strcat(l[8]->help, "ON :\ntype gives the specifications o");
	l[8]->help = ft_strcat(l[8]->help, "f the command.\n");
	l[9] = (t_builtin *)malloc(sizeof(t_builtin));
	l[9]->name = ft_strdup("builtin");
	l[9]->help = (char *)malloc(sizeof(char) * 89);
	l[9]->help = ft_strcpy(l[9]->help, "USAGE :\nbuiltin [name [argument ..].");
	l[9]->help = ft_strcat(l[9]->help, "\n\nDESCRIPTION :\nbuiltin execute a ");
	l[9]->help = ft_strcat(l[9]->help, "builtin commands.\n");
	l[10] = (t_builtin *)malloc(sizeof(t_builtin));
	l[10]->name = NULL;
	l[10]->help = NULL;
	return (l);
}

t_builtin	**init_listbuiltin3(t_builtin **l)
{
	l[3]->help = ft_strcat(l[3]->help, "s equivalent to: setenv name value 1");
	l[3]->help = ft_strcat(l[3]->help, "\n");
	l[4] = (t_builtin *)malloc(sizeof(t_builtin));
	l[4]->name = ft_strdup("pwd");
	l[4]->help = (char *)malloc(sizeof(char) * 69);
	l[4]->help = ft_strcpy(l[4]->help, "USAGE :\npwd\n\nDESCRIPTION :\npwd pr");
	l[4]->help = ft_strcat(l[4]->help, "int the current working directory.\n");
	l[5] = (t_builtin *)malloc(sizeof(t_builtin));
	l[5]->name = ft_strdup("echo");
	l[5]->help = (char *)malloc(sizeof(char) * 254);
	l[5]->help = ft_strcpy(l[5]->help, "USAGE :\necho [-n] [string ...] n\nDE");
	l[5]->help = ft_strcat(l[5]->help, "SCRIPTION :\necho writes any specifie");
	l[5]->help = ft_strcat(l[5]->help, "d operands, separated by single blank");
	l[5]->help = ft_strcat(l[5]->help, " (\" \") characters and followed by a");
	l[5]->help = ft_strcat(l[5]->help, " newline (\"\n\") character, to the s");
	l[5]->help = ft_strcat(l[5]->help, "tandard output.\nThe \"-n\" option wi");
	l[5]->help = ft_strcat(l[5]->help, "ll remove the trailing newline charac");
	l[5]->help = ft_strcat(l[5]->help, "ter.\n");
	l[6] = (t_builtin *)malloc(sizeof(t_builtin));
	l[6]->name = ft_strdup("cd");
	l[6]->help = (char *)malloc(sizeof(char) * 175);
	l[6]->help = ft_strcpy(l[6]->help, "USAGE :\ncd [path] n\nDESCRIPTION :\n");
	l[6]->help = ft_strcat(l[6]->help, "cd move the current working directory");
	l[6]->help = ft_strcat(l[6]->help, " to the specified path. If path is no");
	return (init_listbuiltin4(l));
}

t_builtin	**init_listbuiltin2(t_builtin **l)
{
	l[1]->help = ft_strcat(l[1]->help, " the variable name pointer to by name");
	l[1]->help = ft_strcat(l[1]->help, " from the l. Note that only the varia");
	l[1]->help = ft_strcat(l[1]->help, "ble name (e.g., \"NAME\") should be g");
	l[1]->help = ft_strcat(l[1]->help, "iven; \"NAME=value\" will not work.\n");
	l[2] = (t_builtin *)malloc(sizeof(t_builtin));
	l[2]->name = ft_strdup("setenv");
	l[2]->help = (char *)malloc(sizeof(char) * 374);
	l[2]->help = ft_strcpy(l[2]->help, "USAGE :\nsetenv name value overwrite");
	l[2]->help = ft_strcat(l[2]->help, "\n\nDESCRIPTION :\nsetenv inserts or ");
	l[2]->help = ft_strcat(l[2]->help, "resets the environment variable name ");
	l[2]->help = ft_strcat(l[2]->help, "in the current environment l.  If the");
	l[2]->help = ft_strcat(l[2]->help, " variable name does not exist in the ");
	l[2]->help = ft_strcat(l[2]->help, "l, it is inserted with the given valu");
	l[2]->help = ft_strcat(l[2]->help, "e. If the variable does exist, the ar");
	l[2]->help = ft_strcat(l[2]->help, "gument overwrite is tested; if overwr");
	l[2]->help = ft_strcat(l[2]->help, "ite is zero, the variable is not rese");
	l[2]->help = ft_strcat(l[2]->help, "t, otherwise it is reset to the given");
	l[2]->help = ft_strcat(l[2]->help, " value.\n");
	l[3] = (t_builtin *)malloc(sizeof(t_builtin));
	l[3]->name = ft_strdup("putenv");
	l[3]->help = (char *)malloc(sizeof(char) * 143);
	l[3]->help = ft_strcpy(l[3]->help, "USAGE :\nputenv name value\n\nDESCRIP");
	l[3]->help = ft_strcat(l[3]->help, "TION :\nputenv function takes an argu");
	l[3]->help = ft_strcat(l[3]->help, "ment of the form \"name=value\" and i");
	return (init_listbuiltin3(l));
}

t_builtin	**init_listbuiltin(void)
{
	t_builtin	**l;

	l = (t_builtin **)malloc(sizeof(t_builtin *) * 11);
	l[0] = (t_builtin *)malloc(sizeof(t_builtin));
	l[0]->name = ft_strdup("env");
	l[0]->help = (char *)malloc(sizeof(char) * 471);
	l[0]->help = ft_strcpy(l[0]->help, "USAGE :\nenv [-i] [name=value ...] [u");
	l[0]->help = ft_strcat(l[0]->help, "tility [argument ...]]\n\nDESCRIPTION");
	l[0]->help = ft_strcat(l[0]->help, " :\nenv executes utility after modify");
	l[0]->help = ft_strcat(l[0]->help, "ing the environment as specified on t");
	l[0]->help = ft_strcat(l[0]->help, "he command line. The option name=valu");
	l[0]->help = ft_strcat(l[0]->help, "e specifies an environmental variable");
	l[0]->help = ft_strcat(l[0]->help, ", name, with a value of value of valu");
	l[0]->help = ft_strcat(l[0]->help, "e. The option '-i' causes env to comp");
	l[0]->help = ft_strcat(l[0]->help, "letly ignore the environment it inher");
	l[0]->help = ft_strcat(l[0]->help, "its.\nIf no utility is specified, env");
	l[0]->help = ft_strcat(l[0]->help, " prints out the names and values of t");
	l[0]->help = ft_strcat(l[0]->help, "he variables in the environment, with");
	l[0]->help = ft_strcat(l[0]->help, " one name=value pair per line.\n");
	l[1] = (t_builtin *)malloc(sizeof(t_builtin));
	l[1]->name = ft_strdup("unsetenv");
	l[1]->help = (char *)malloc(sizeof(char) * 214);
	l[1]->help = ft_strcpy(l[1]->help, "USAGE :\nunsetenv name\n\nDESCRIPTION");
	l[1]->help = ft_strcat(l[1]->help, " :\nunsetenv deletes all instances of");
	return (init_listbuiltin2(l));
}
