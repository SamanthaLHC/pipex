/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:51:11 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/08 14:15:25 by sam              ###   ########.fr       */
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
#include <sys/types.h>
#include <sys/wait.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_utils
{
	int		fd_file1;
	int		fd_file2;
	int		fd_pipe[2];
	int		status;
	char	*exec_path_cmd1;
	char	*exec_path_cmd2;
	char	**cmd1_options;
	char	**cmd2_options;

}			t_utils;

/* ************************************************************************** */
/*    utils.c                                                                 */
/* ************************************************************************** */
void	free_split(char	**tab);
void	init_path(t_utils *utils);

/* ************************************************************************** */
/*    exec.c                                                                  */
/* ************************************************************************** */
void	proc_first_child(t_utils *utils, char **env);
void	proc_second_child(t_utils *utils, char **env);
void	execute_cmd_line(t_utils *utils, char **env);

/* ************************************************************************** */
/*    pipex.c                                                                 */
/* ************************************************************************** */
int		get_fd(char **input, t_utils *utils);

/* ************************************************************************** */
/*   path.c                                                                   */
/* ************************************************************************** */
char	**get_path(char **envp);
void	error_paths(char **tab_paths, char *input);
char	*check_exec_path(char **tab_paths, char *input);
char	*get_exec_path(char *input, char **envp);
char	**get_options_cmd(char	*input);

#endif