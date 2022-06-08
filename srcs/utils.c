/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:29:57 by sam               #+#    #+#             */
/*   Updated: 2022/06/08 14:03:56 by sam              ###   ########.fr       */
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