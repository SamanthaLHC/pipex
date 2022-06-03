/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:50:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/03 17:01:12 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(char **input, t_utils *utils)
{
	utils->fd_file1 = open(input[1], O_RDONLY);
	utils->fd_file2 = open(input[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (utils->fd_file1 == -1)
	{
		ft_printf("%d\n", errno);
		perror("issue with open");
		if (utils->fd_file1 != -1)
			close(utils->fd_file1);
		if (utils->fd_file2 != -1)
			close(utils->fd_file2);
		return (-1);
	}
	if (utils->fd_file2 == -1)
	{
		ft_printf("%d\n", errno);
		perror("issue with open");
		if (utils->fd_file1 != -1)
			close(utils->fd_file1);
		if (utils->fd_file2 != -1)
			close(utils->fd_file2);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_utils	*utils;
	
	utils = NULL;
	if (ac != 5)
		ft_putstr_fd("Error\npipex usage: file1 cmd1 | cmd2 file2\n", 2);
	get_fd(av, utils);
	utils->cmd1_options = get_options_cmd(av[2]);
	utils->exec_path_cmd1 = get_exec_path(utils->cmd1_options[0], env);
	utils->cmd2_options = get_options_cmd(av[3]);
	utils->exec_path_cmd2 = get_exec_path(utils->cmd2_options[0], env);
	execute_cmd_line(utils, env);
	free_split(utils->cmd1_options);
	free_split(utils->cmd2_options);
	free (utils->exec_path_cmd1);
	free (utils->exec_path_cmd2);
	return (utils->status);
}
