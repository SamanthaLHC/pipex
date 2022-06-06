/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:50:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/06 20:30:22 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_exec_path(t_utils *utils)
{
	free_split(utils->cmd1_options);
	free_split(utils->cmd2_options);
	free (utils->exec_path_cmd1);
	free (utils->exec_path_cmd2);
	return (0);
}

void	error_file(char *input, t_utils *utils)
{
	perror(input);
	if (utils->fd_file1 != -1)
		close(utils->fd_file1);
	if (utils->fd_file2 != -1)
		close(utils->fd_file2);
}

int	get_fd(char **input, t_utils *utils)
{
	utils->fd_file1 = 0;
	utils->fd_file2 = 0;
	utils->fd_file1 = open(input[1], O_RDONLY);
	if (utils->fd_file1 == -1)
		error_file(input[1], utils);
	utils->fd_file2 = open(input[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (utils->fd_file2 == -1)
		error_file(input[4], utils);
	if (utils->fd_file1 == -1 || utils->fd_file2 == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_utils	utils;

	if (ac != 5)
	{
		ft_putstr_fd("Error\npipex usage: file1 cmd1 | cmd2 file2\n", 2);
		return (1);
	}
	if (get_fd(av, &utils) == -1)
		return (1);
	utils.cmd1_options = get_options_cmd(av[2]);
	utils.exec_path_cmd1 = get_exec_path(utils.cmd1_options[0], env);
	if (!utils.exec_path_cmd1)
		return (free_exec_path(&utils));
	utils.cmd2_options = get_options_cmd(av[3]);
	utils.exec_path_cmd2 = get_exec_path(utils.cmd2_options[0], env);
	if (!utils.exec_path_cmd2)
	{
		free_exec_path(&utils);
		return (1);
	}
	execute_cmd_line(&utils, env);
	free_exec_path(&utils);
	return (utils.status);
}
