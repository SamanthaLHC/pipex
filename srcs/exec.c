/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:08:09 by sam               #+#    #+#             */
/*   Updated: 2022/06/02 20:59:23 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_first_child(t_utils *utils)
{
	dup2(utils->fd1, STDOUT_FILENO);
	close(fd[0])
	close(fd[1])
	execve(utils->exec_path, ,);
	return 0;
}

int	fork_second_child()
{
	int pid2 = fork();
	if (pid2 < 0)
	return 1
	if pid2 == 0
	dup2(fd[0]), STDIN_FILENO);
	close(fd[0])
	close(fd[1])
	execve();
}

void	execute_cmd_line(t_utils *utils, char *cmd1, char *cmd2)
{
	int		fd[2];
	pid_t	first_child;
	pid_t	second_child;

	if (pipe(fd) == -1)
		return (perror("pipe issue"));
	first_child = fork();
	if (first_child == -1)
		return (perror("fork issue"));
	if (first_child == 0)
		fork_first_child();
	second_child = fork();
	if (second_child == -1)
		return (perror("fork issue"));
	if (second_child == 0)
		fork_second_child();
	close(fd[0]);
	close(fd[1]);
	waitpid(first_child, NULL, 0);
	waitpid(second_child, NULL, 0);
}
