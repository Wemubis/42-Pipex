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
int		check_args(char **av, char *cmd1, char *cmd2);
int		left_hand_pipe(int child_pid_1, int fd[3], char ***cmd);
int		right_hand_pipe(int child_pid_2, int fd[3], char ***cmd);

/*--------------- FUNCTION ----------------*/
int		ft_pipex(char **av);

#endif
