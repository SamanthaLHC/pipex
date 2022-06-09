/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:08:09 by sam               #+#    #+#             */
/*   Updated: 2022/06/10 00:10:33 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	proc_first_child(t_utils *utils, char **env)
{
	if (utils->fd_file1 == -1)
	{
		close_fd(utils);
		free_exec_path(utils);
		exit(1);
	}
	if (dup2(utils->fd_file1, STDIN_FILENO) == -1)
		perror("");
	if (dup2(utils->fd_pipe[1], STDOUT_FILENO) == -1)
		perror("");
	close_fd(utils);
	if (!utils->exec_path_cmd1)
	{
		close_fd(utils);
		free_exec_path(utils);
		exit(1);
	}
	if (execve(utils->exec_path_cmd1, utils->cmd1_options, env) == -1)
	{
		perror("");
		free_exec_path(utils);
		close_fd(utils);
		exit(1);
	}
}

void	proc_second_child(t_utils *utils, char **env)
{
	if (utils->fd_file2 == -1)
	{
		close_fd(utils);
		free_exec_path(utils);
		exit(1);
	}
	if (dup2(utils->fd_file2, STDOUT_FILENO) == -1)
		perror("");
	if (dup2(utils->fd_pipe[0], STDIN_FILENO) == -1)
		perror("");
	close_fd(utils);
	if (!utils->exec_path_cmd2)
	{
		close_fd(utils);
		free_exec_path(utils);
		exit(1);
	}
	if (execve(utils->exec_path_cmd2, utils->cmd2_options, env) == -1)
	{
		perror("");
		free_exec_path(utils);
		close_fd(utils);
		exit(1);
	}
}

void	execute_cmd_line(t_utils *utils, char **env)
{
	pid_t	first_child;
	pid_t	second_child;

	if (pipe(utils->fd_pipe) == -1)
		return (perror(""));
	first_child = fork();
	if (first_child == -1)
		return (perror(""));
	if (first_child == 0)
		proc_first_child(utils, env);
	second_child = fork();
	if (second_child == -1)
		return (perror(""));
	if (second_child == 0)
		proc_second_child(utils, env);
	close_fd(utils);
	waitpid(first_child, NULL, 0);
	waitpid(second_child, &utils->status, 0);
}
