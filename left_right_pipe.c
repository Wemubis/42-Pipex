/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:28:16 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/06 17:28:33 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	left_hand_pipe(int child_pid_1, int fd[3], char ***cmd)
{
	if (child_pid_1 < 0)
	{
		perror("fork child_pid_1");
		exit(EXIT_FAILURE);
	}
	if (child_pid_1 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[2], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(fd[2]);
		execve(cmd[0][0], cmd[0], NULL);
	}
	return (0);
}

int	right_hand_pipe(int child_pid_2, int fd[3], char ***cmd)
{
	if (child_pid_2 < 0)
	{
		perror("fork child_pid_2");
		exit(EXIT_FAILURE);
	}
	if (child_pid_2 == 0)
	{
		dup2(fd[2], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(fd[2]);
		execve(cmd[1][0], cmd[1], NULL);
	}
	return (0);
}
