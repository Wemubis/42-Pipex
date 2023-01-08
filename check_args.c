/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:35:07 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/06 14:26:24 by mle-boud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_files(char *file_1, char *file_2)
{
	int	f1;
	int	f2;

	f1 = open(file_1, O_RDONLY);
	if (f1 == -1)
		errors_process("file 1");
	close(f1);
	f2 = open(file_2, O_CREAT, 0644);
	if (f2 == -1)
		errors_process("file 1");
	close(f2);
}

static void	check_cmd(char *cmd1, char *cmd2)
{
	char	*path_cmd[2];
	int		access_cmd[2];

	path_cmd[0] = ft_strjoin("/usr/bin/", cmd1);
	path_cmd[1] = ft_strjoin("/usr/bin/", cmd2);
	access_cmd[0] = access(path_cmd[0], F_OK);
	if (access_cmd[0] == -1)
		errors_process("cmd1");
	access_cmd[1] = access(path_cmd[1], F_OK);
	if (access_cmd[1] == -1)
		errors_process("cmd2");
}

void	check_args(char **av, char *cmd1, char *cmd2)
{
	check_files(av[1], av[4]);
	check_cmd(cmd1, cmd2);
}
