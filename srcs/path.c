/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:50:04 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/27 13:06:13 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//FREE LES MALLOCS

int	get_fd(char **input)
{
	int	fd1;
	int	fd2;

	fd1 = open(input[1], O_RDONLY);
	fd2 = open(input[4], O_WRONLY | O_CREAT | O_TRUNC, 644);
	if (fd1 == -1 || fd2 == -1)
	{
		ft_printf("%d\n", errno);
		perror("issue with open");
		if (fd1 != -1)
			close(fd1);
		if (fd2 != -1)
			close(fd2);
		return (-1);
	}
	return (0);

	// mettre les fd dans un tab ?
	//!!!!!!!!!!!!!!!!!!!!
	//gerer erreur si le file2 a deja des droits (autre que 644) voir access
	//!!!!!!!!!!!!!!!!!!!!
}

char	**get_path(char **envp)
{
	int		i;
	char	*path;
	char	**tab_paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path = envp[i];
	tab_paths = ft_split(path, ':');
	if (!tab_paths)
		return (NULL);
	return (tab_paths);
}

char	*error_paths(char **input, char **envp)
{
	int		i;
	char	**tab_paths;
	char	*exec_path;

	i = 0;
	tab_paths = get_path(envp);
	if (!tab_paths)
		return (NULL);
	while (tab_paths && tab_paths[i])
	{
		exec_path = ft_strjoin(tab_paths[i], "/", input[2]);
		if (!exec_path)
		{
			free (tab_paths);
			return (NULL);
		}
		if (access(exec_path, F_OK) == 0)
		{
			if (access(exec_path, X_OK) == -1)
			{
				free (exec_path);
				free (tab_paths);
				return (("permission denied: %s\n", input[2]));
			}
		}
		free (exec_path);
		i++;
	}
	free (tab_paths);
	return (ft_printf("command not found: %s\n", input[2]));
}

char	*check_and_get_exec_path(char *input, char **envp)
{	
	int		i;
	char	**tab_paths;
	char	*exec_path;

	i = 0;
	tab_paths = get_path(envp);
	if (!tab_paths)
		return (NULL);
	while (tab_paths && tab_paths[i])
	{
		exec_path = ft_strjoin(exec_path[i], "/", input[2]);
		if (!exec_path)
		{
			free (tab_paths);
			return (NULL);
		}
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			free(tab_paths);
			return (exec_path);
		}
		i++;
	}
	return (error_paths(tab_paths, envp));
}

/*
Pour tester les paths valides: ouvrir un terminal 
faire export PATH=*inserer path*
creer des dir avec:
path mais aucun droits
 aucun chemin
chemin invalide
cmd ./dir
*/
