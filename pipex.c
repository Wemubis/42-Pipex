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

int	ft_pipex(char **av)
{
	int		fd[3];
	char	**cmd[2];
	int		child_pid[2];

	cmd[0] = ft_split(av[2], 32);
	cmd[1] = ft_split(av[3], 32);
	check_args(av, cmd[0][0], cmd[1][0]);
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[4], O_WRONLY | O_TRUNC);
	child_pid[0] = fork();
	left_hand_pipe(child_pid[0], fd, cmd);
	child_pid[1] = fork();
	right_hand_pipe(child_pid[1], fd, cmd);
	close(fd[0]);
	close(fd[1]);
	waitpid(child_pid[0], NULL, 0);
	waitpid(child_pid[1], NULL, 0);
	return (0);
}
