/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:06:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/09 13:06:40 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char *file_1, char *file_2)
{
	int	f1;
	int	f2;

	f1 = open(file_1, O_RDONLY);
	if (f1 < 0)
		errors_process();
	close(f1);
	f2 = open(file_2, O_CREAT, 0644);
	if (f2 < 0)
		errors_process();
	close(f2);
}
