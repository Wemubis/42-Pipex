/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:27:38 by mle-boud          #+#    #+#             */
/*   Updated: 2022/12/14 17:27:38 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_pipex(char **av)
{
    int     fd[2];
    char    **cmd[2];
    int     child_pid[2];

    cmd[0] = ft_split(av[2], " ");
    cmd[1] = ft_split(av[3], " ");
    check_errors(ac, av, cmd[0][0], cmd[1][0]);
    fd[0] = av[1];
    fd[1] = av[4];
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return (2);
    }
    
    child_pid[0] = fork();
    if (child_pid[0] < 0)
    {
        perror("fork child_pid[0]");
        return (2);
    }
    if (child_pid[0] == 0)
    {
        // before the pipe
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(cmd[0][0], cmd[0], NULL);
    }

    child_pid[1] = fork();
    if (child_pid[1] < 0)
    {
        perror("fork child_pid[1]");
        return (2);
    }
    if (child_pid[1] == 0)
    {
        // after the pipe
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(cmd[1][0], cmd[1], NULL);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(child_pid[0], NULL, 0);
    waitpid(child_pid[1], NULL, 0);

    return (0);
}
