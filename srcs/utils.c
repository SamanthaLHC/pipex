/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:29:57 by sam               #+#    #+#             */
/*   Updated: 2022/06/08 23:17:35 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char	**tab)
{
	int	i;

	i = 0;
	if (tab != NULL && tab[i])
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
	utils->cmd1_options = NULL;
	utils->cmd2_options = NULL;
	utils->exec_path_cmd1 = NULL;
	utils->exec_path_cmd2 = NULL;
}

int	free_exec_path(t_utils *utils)
{
	free_split(utils->cmd1_options);
	free_split(utils->cmd2_options);
	free (utils->exec_path_cmd1);
	free (utils->exec_path_cmd2);
	return (0);
}

void	print_error(char *input)
{
	ft_putstr_fd("Command not found: ", 2);
	write(2, input, ft_strlen(input));
	write(2, "\n", 1);
}
