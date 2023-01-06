/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:35:07 by mle-boud          #+#    #+#             */
/*   Updated: 2022/12/14 17:35:07 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_files(char *file_1, char *file_2)
{
    int f1;
    int f2;

    f1 = open(file_1, O_RDONLY);
    if (f1 == -1)
    {
        perror("file_1");
        exit(EXIT_FAILURE);
    }
    close(file_1);
    f2 = open(file_2, O_WRONLY | O_CREAT, 0644);
    if (f2 == -1)
    {
        perror("file_2");
        exit(EXIT_FAILURE);
    }
    close(file_2);
    return (0);
}

int check_cmd(char *cmd1, char *cmd2)
{
    char    *path_cmd[2];

    path_cmd[0] = ft_strjoin("/usr/bin/", cmd1);
    path_cmd[1] = ft_strjoin("/usr/bin/", cmd2);
    access("path_cmd[0]", F_OK);
    if (f1 == -1)
    {
        perror("path_cmd[0]");
        exit(EXIT_FAILURE);
    }
    access("path_cmd[1]", F_OK);
    if (f1 == -1)
    {
        perror("path_cmd[1]");
        exit(EXIT_FAILURE);
    }
    return (0);
}

int check_errors(char **av, char *cmd1, char *cmd2)
{
    check_files(av[1], av[4]);
    check_cmd(av[2], av[3], cmd1, cmd2);
    return (0);
}
