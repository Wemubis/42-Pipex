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

static int	check_files(char *file_1, char *file_2)
{
	int	f1;
	int	f2;

	f1 = open(file_1, O_RDONLY);
	if (f1 == -1)
	{
		perror("file_1");
		exit(EXIT_FAILURE);
	}
	close(f1);
	f2 = open(file_2, O_WRONLY | O_CREAT, 0777);
	if (f2 == -1)
	{
		perror("file_2");
		exit(EXIT_FAILURE);
	}
	close(f2);
	return (0);
}

static int	check_cmd(char *cmd1, char *cmd2)
{
	char	*path_cmd[2];
	int		access_cmd1;
	int		access_cmd2;

	path_cmd[0] = ft_strjoin("/usr/bin/", cmd1);
	path_cmd[1] = ft_strjoin("/usr/bin/", cmd2);
	access_cmd1 = access(path_cmd[0], F_OK);
	if (access_cmd1 == -1)
	{
		perror("cmd1");
		exit(EXIT_FAILURE);
	}
	access_cmd2 = access(path_cmd[1], F_OK);
	if (access_cmd2 == -1)
	{
		perror("cmd2");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	check_args(char **av, char *cmd1, char *cmd2)
{
	check_files(av[1], av[4]);
	check_cmd(cmd1, cmd2);
	return (0);
}
