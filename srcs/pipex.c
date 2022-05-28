/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:50:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/28 16:43:43 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_options_cmd(char	*input)
{
	char	**options;

	options = ft_split(input, ' ');
	if (!options)
		return (NULL);
	return (options);
}

int main(int ac, char **av, char **env)
{
	char **cmd_options;

	cmd_options = get_options_cmd(av[2]);
	char	*exec_path;
	(void)av;
	if (ac != 5)
		ft_putstr_fd("Error\npipex usage: file1 cmd1 | cmd2 file2", 2);
	exec_path = get_exec_path(cmd_options[0], env);
	//get_exec_path(av[3], env);
	free_split(cmd_options);
	free (exec_path);
}
