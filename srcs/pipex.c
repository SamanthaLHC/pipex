/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:50:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/02 20:37:09 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(char **input, t_utils *utils)
{
	utils->fd1 = open(input[1], O_RDONLY);
	utils->fd2 = open(input[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (utils->fd1 == -1 || utils->fd2 == -1)
	{
		ft_printf("%d\n", errno);
		perror("issue with open");
		if (utils->fd1 != -1)
			close(utils->fd1);
		if (utils->fd2 != -1)
			close(utils->fd2);
		return (-1);
	}
	return (0);
}
// separer les verif car errno pas garanti si deuxieme commande reuss
//et premiere echoue

char	**get_options_cmd(char	*input)
{
	char	**options;

	options = ft_split(input, ' ');
	if (!options)
		return (NULL);
	return (options);
}

int	main(int ac, char **av, char **env)
{
	char	**cmd_options;
	t_utils	*utils;

	if (ac != 5)
		ft_putstr_fd("Error\npipex usage: file1 cmd1 | cmd2 file2\n", 2);
	get_fd(av, &utils);
	cmd_options = get_options_cmd(av[2]);
	utils->exec_path = get_exec_path(cmd_options[0], env);
	//get_exec_path(av[3], env);
	free_split(cmd_options);
	free (utils->exec_path);
}
