/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:27:38 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/06 14:23:38 by mle-boud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(char **av, char **env)
{
	int		fd[2];
	int		fd_piped[2];
	char	**cmd[2];
	pid_t	child_pid;

	cmd[0] = ft_split(av[2], 32);
	cmd[1] = ft_split(av[3], 32);
	check_args(av, cmd[0][0], cmd[1][0]);
	if (pipe(fd_piped) < 0)
		errors_process("pipe");
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[4], O_WRONLY | O_TRUNC);
	child_pid = fork();
	if (child_pid < 0)
		errors_process("fork 1");
	if (child_pid == 0)
		left_hand_pipe(fd[0], fd_piped, cmd[0]);
	child_pid = fork();
	if (child_pid < 0)
		errors_process("fork 2");
	if (child_pid == 0)
		right_hand_pipe(fd[1], fd_piped, cmd[1]);
	close_fds(fd);
	close_fds(fd_piped);
	wait_pids(child_pid);
}
