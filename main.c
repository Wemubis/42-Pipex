/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:34:42 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/07 12:34:42 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		write(1, "e.g.: ./pipex file1 cmd1 cmd2 file2\n", 36);
		exit(EXIT_FAILURE);
	}
	else
		ft_pipex(av, env);
	return (0);
}
