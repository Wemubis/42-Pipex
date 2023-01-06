/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:44:10 by marvin            #+#    #+#             */
/*   Updated: 2023/01/05 00:44:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
    if (ac != 5)
    {
        write(1, "e.g.: ./pipex file1 cmd1 cmd2 file2\n", 36);
        exit(EXIT_FAILURE);
    }
    else
        ft_pipex(av);
    return (0);
}