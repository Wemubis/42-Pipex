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

void	left_hand_pipe(int fd, int fd_piped[2], char **av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av[2], 32);
	path = get_path(cmd[0], env);
	dup2(fd, STDIN_FILENO);
	dup2(fd_piped[1], STDOUT_FILENO);
	close(fd);
	close_fds(fd_piped);
	if (execve(path, cmd, NULL) == -1)
		errors_process("execve");
}

void	right_hand_pipe(int fd, int fd_piped[2], char **av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av[3], 32);
	path = get_path(cmd[0], env);
	dup2(fd_piped[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close_fds(fd_piped);
	if (execve(path, cmd, NULL) == -1)
		errors_process("execve");
}
