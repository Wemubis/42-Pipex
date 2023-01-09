/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:18:05 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/09 10:18:05 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*strcat_path(char *path, char *cmd)
{
	char	*temp;

	temp = malloc(sizeof(char *) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	ft_strcat(temp, path);
	ft_strcat(temp, "/");
	ft_strcat(temp, cmd);
	return (temp);
}

static char	**find_path(char **env)
{
	int		i;
	char	**dst;

	i = 0;
	dst = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", ft_strlen(env[i])))
		{
			dst = ft_split(env[i], ':');
			dst[0] = ft_substr(dst[0], 5, 100);
			break ;
		}
		i++;
	}
	return (dst);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*dst;

	path = find_path(env);
	i = 0;
	while (path[i])
	{
		dst = strcat_path(path[i], cmd);
		if (access(dst, X_OK) != -1)
		{
			i = 0;
			break ;
		}
		i++;
	}
	if (i > 0)
		errors_process(cmd);
	return (dst);
}
