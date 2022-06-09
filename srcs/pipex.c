/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:50:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/10 00:11:30 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_cmd1(t_utils *utils, char *av, char **env)
{
	utils->cmd1_options = get_options_cmd(av);
	utils->exec_path_cmd1 = get_exec_path(utils->cmd1_options[0], env);
}

void	handle_cmd2(t_utils *utils, char *av, char **env)
{
	utils->cmd2_options = get_options_cmd(av);
	utils->exec_path_cmd2 = get_exec_path(utils->cmd2_options[0], env);
}

/*
void	error_file(char *input, t_utils *utils)
{
	perror(input);
	if (utils->fd_file1 != -1)
		close(utils->fd_file1);
	if (utils->fd_file2 != -1)
		close(utils->fd_file2);
}
*/

int	get_fd(char **input, t_utils *utils)
{
	utils->fd_file1 = 0;
	utils->fd_file2 = 0;
	utils->fd_file1 = open(input[1], O_RDONLY);
	if (utils->fd_file1 == -1)
		perror(input[1]);
	utils->fd_file2 = open(input[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (utils->fd_file2 == -1)
		perror(input[4]);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_utils	utils;

	init_path(&utils);
	if (ac != 5)
	{
		ft_putstr_fd("Error\npipex usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	get_fd(av, &utils);
	handle_cmd1(&utils, av[2], env);
	if (!utils.exec_path_cmd1)
		print_error(utils.cmd1_options[0]);
	handle_cmd2(&utils, av[3], env);
	if (!utils.exec_path_cmd2)
	{
		print_error(utils.cmd2_options[0]);
		return (free_exec_path(&utils));
	}
	execute_cmd_line(&utils, env);
	free_exec_path(&utils);
	return (utils.status);
}

/*
int	main(int ac, char **av, char **env)
{
	t_utils	utils;

	init_path(&utils);
	if (ac != 5)
	{
		ft_putstr_fd("Error\npipex usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	if (get_fd(av, &utils) == -1)
		return (1);
	handle_cmd1(&utils, av[2], env);
	if (!utils.exec_path_cmd1)
	{
		print_error(utils.cmd1_options[0]);
		return (free_exec_path(&utils));
	}
	handle_cmd2(&utils, av[3], env);
	if (!utils.exec_path_cmd2)
	{
		print_error(utils.cmd2_options[0]);
		return (free_exec_path(&utils));
	}
	execute_cmd_line(&utils, env);
	free_exec_path(&utils);
	return (utils.status);
}
*/