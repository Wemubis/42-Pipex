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

/*----------- FUNCTION + UTILS ------------*/
int 	check_errors(char **av, char *cmd1, char *cmd2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int     ft_pipex(char **av);

#endif
