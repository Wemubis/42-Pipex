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
# include <string.h>
# include <errno.h>
# include "libft/libft.h"

/*----------------- UTILS -----------------*/
void	error_open(int fd);
void	errors_process(void);
void	close_fds(int fd[2]);
void	wait_pids(int child_pid[2]);
void	check_files(char *file_1, char *file_2);
char	*get_path(char *cmd, char **env);
void	left_hand_pipe(int fd, int fd_piped[2], char **av, char **env);
void	right_hand_pipe(int fd, int fd_piped[2], char **av, char **env);

/*--------------- FUNCTION ----------------*/
void	ft_pipex(char **av, char **env);

#endif
