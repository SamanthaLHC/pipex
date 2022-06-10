/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:29:57 by sam               #+#    #+#             */
/*   Updated: 2022/06/10 15:54:50 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char	**tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	init_path(t_utils *utils)
{
	utils->fd_file1 = -1;
	utils->fd_file2 = -1;
	utils->fd_pipe[0] = -1;
	utils->fd_pipe[1] = -1;
	utils->cmd1_options = NULL;
	utils->cmd2_options = NULL;
	utils->exec_path_cmd1 = NULL;
	utils->exec_path_cmd2 = NULL;
}

int	free_exec_path(t_utils *utils)
{
	free_split(utils->cmd1_options);
	free_split(utils->cmd2_options);
	free(utils->exec_path_cmd1);
	free(utils->exec_path_cmd2);
	return (0);
}

void	close_fd(t_utils *utils)
{
	if (utils->fd_file1 != -1)
		close(utils->fd_file1);
	if (utils->fd_file2 != -1)
		close(utils->fd_file2);
	if (utils->fd_pipe[0] != -1)
		close(utils->fd_pipe[0]);
	if (utils->fd_pipe[1] != -1)
		close(utils->fd_pipe[1]);
}

void	print_error(char *input)
{
	ft_putstr_fd("Command not found: ", 2);
	write(2, input, ft_strlen(input));
	write(2, "\n", 1);
}
