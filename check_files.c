/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:35:07 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/06 14:26:24 by mle-boud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char *file_1, char *file_2)
{
	int	f1;
	int	f2;

	f1 = open(file_1, O_RDONLY);
	if (f1 == -1)
		errors_process("file 1");
	close(f1);
	f2 = open(file_2, O_CREAT, 0644);
	if (f2 == -1)
		errors_process("file 1");
	close(f2);
}
