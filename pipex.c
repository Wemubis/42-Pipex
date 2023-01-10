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
	pid_t	child_pid[2];

	check_files(av[1], av[4]);
	if (pipe(fd_piped) < 0)
		errors_process();
	fd[0] = open(av[1], O_RDONLY);
	error_open(fd[0]);
	fd[1] = open(av[4], O_WRONLY | O_TRUNC);
	error_open(fd[1]);
	child_pid[0] = fork();
	if (child_pid[0] < 0)
		errors_process();
	if (child_pid[0] == 0)
		left_hand_pipe(fd[0], fd_piped, av, env);
	child_pid[1] = fork();
	if (child_pid[1] < 0)
		errors_process();
	if (child_pid[1] == 0)
		right_hand_pipe(fd[1], fd_piped, av, env);
	close_fds(fd);
	close_fds(fd_piped);
	wait_pids(child_pid);
}
