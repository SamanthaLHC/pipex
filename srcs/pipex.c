/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:50:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/25 15:15:34 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int ac, char **av, char **env)
{
	(void)av;
	if (ac != 5)
		ft_putstr_fd("Error\npipex usage: file1 cmd1 | cmd2 file2", 2);
	get_path(env);
}