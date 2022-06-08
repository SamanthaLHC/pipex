/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:08:09 by sam               #+#    #+#             */
/*   Updated: 2022/06/08 23:10:07 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	proc_first_child(t_utils *utils, char **env)
{
	close(utils->fd_file2);
	close(utils->fd_pipe[0]);
	if (dup2(utils->fd_file1, STDIN_FILENO) == -1)
		perror("");
	if (dup2(utils->fd_pipe[1], STDOUT_FILENO) == -1)
		perror("");
	close(utils->fd_pipe[1]);
	close(utils->fd_file1);
	if (execve(utils->exec_path_cmd1, utils->cmd1_options, env) == -1)
	{
		perror("");
		exit(1);
	}
}

void	proc_second_child(t_utils *utils, char **env)
{
	close(utils->fd_file1);
	close(utils->fd_pipe[1]);
	if (dup2(utils->fd_file2, STDOUT_FILENO) == -1)
		perror("");
	if (dup2(utils->fd_pipe[0], STDIN_FILENO) == -1)
		perror("");
	close(utils->fd_pipe[0]);
	close(utils->fd_file2);
	if (execve(utils->exec_path_cmd2, utils->cmd2_options, env) == -1)
	{
		perror(utils->exec_path_cmd2);
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
	close(utils->fd_pipe[0]);
	close(utils->fd_pipe[1]);
	close(utils->fd_file1);
	close(utils->fd_file2);
	waitpid(first_child, NULL, 0);
	waitpid(second_child, &utils->status, 0);
}
