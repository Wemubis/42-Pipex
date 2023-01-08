/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:27:35 by mle-boud          #+#    #+#             */
/*   Updated: 2022/12/14 17:27:35 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*---------------- HEADERS ----------------*/
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

/*----------------- UTILS -----------------*/
void	close_fds(int fd[2]);
void	wait_pids(int child_pid);
void	errors_process(char *string);
void	check_args(char **av, char *cmd1, char *cmd2);
void	left_hand_pipe(int fd, int fd_piped[2], char **cmd);
void	right_hand_pipe(int fd, int fd_piped[2], char **cmd);

/*--------------- FUNCTION ----------------*/
void	ft_pipex(char **av, char **env);

#endif
