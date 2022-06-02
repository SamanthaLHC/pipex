/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:51:11 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/02 20:35:47 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_utils
{
	int		fd1;
	int		fd2;
	char	*exec_path;

}		t_utils;

/* ************************************************************************** */
/*    utils.c                                                                 */
/* ************************************************************************** */
void	free_split(char	**tab);

/* ************************************************************************** */
/*    exec.c                                                                  */
/* ************************************************************************** */

/* ************************************************************************** */
/*   path.c                                                                   */
/* ************************************************************************** */
int		get_fd(char **input, t_utils *utils);
char	**get_path(char **envp);
char	*get_exec_path(char *input, char **envp);

#endif