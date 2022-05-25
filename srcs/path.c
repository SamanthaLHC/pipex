/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:50:04 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/25 18:03:40 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(char **input)
{
	int	fd1;
	int	fd2;

	fd1 = open(input[1], O_RDONLY);
	fd2 = open(input[4], O_WRONLY | O_CREAT | O_TRUNC, 644);
	if (fd1 == -1 || fd2 == -1)
		perror("issue with open");


	// mettre les fd dans un ta b ?
	
	//!!!!!!!!!!!!!!!!!!!!
	// gestion d erreur si le fichier 1 n existe pas ou si le files 


	//!!!!!!!!!!!!!!!!!!!!!!
	//ou si le file2 a deja des droits (autre que 644) voire access
	//!!!!!!!!!!!!!!!!!!!!	
}

char	**get_path(char **envp)
{
	int	i;
	char	*path;
	char	**tab_path;
		
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;	
	path = envp[i];
	tab_path = ft_split(path, ':');
	return (tab_path);
}

char	*get_exec_cmd()
{
	char	*path;
	char	*exec_path;
	int		i;

	i = 0;
	path = get_path;
	while(path[i])
	{
		exec_path = ft_strjoin(exec_path[i], "/");
		//freeeeeeeee
	}
	
	//parcourir le tableau de paths possible jusqua tomber sur celui compatible avec la cmd
	//concat avec / le path et la cmd
	// return la ligne de cmd executable
}
