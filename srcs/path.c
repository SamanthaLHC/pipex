/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:50:04 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/08 13:28:57 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	path = envp[i] + 5;
	tab_paths = ft_split(path, ':');
	if (!tab_paths)
		return (NULL);
	return (tab_paths);
}

void	error_paths(char **tab_paths, char *input)
{
	int		i;
	char	*exec_path;

	i = 0;
	while (tab_paths && tab_paths[i])
	{
		exec_path = ft_strjoin(tab_paths[i], "/", input);
		if (!exec_path)
			return ;
		if (access(exec_path, F_OK) == 0)
		{
			if (access(exec_path, X_OK) == -1)
			{
				free (exec_path);
				ft_putstr_fd("Permission denied: ", 2);
				write(2, input, ft_strlen(input));
				return ;
			}
		}
		free (exec_path);
		i++;
	}
	ft_putstr_fd("Command not found: ", 2);
	write(2, input, ft_strlen(input));
	return ;
}

char	*check_exec_path(char **tab_paths, char *input)
{
	int		i;
	char	*exec_path;

	i = 0;
	while (tab_paths && tab_paths[i])
	{
		exec_path = ft_strjoin(tab_paths[i], "/", input);
		if (!exec_path)
			return (NULL);
		if (access(exec_path, F_OK | X_OK) == 0)
			return (exec_path);
		free (exec_path);
		i++;
	}
	error_paths(tab_paths, input);
	return (NULL);
}

char	**get_options_cmd(char	*input)
{
	char	**options;

	options = ft_split(input, ' ');
	if (!options)
		return (NULL);
	return (options);
}

char	*get_exec_path(char *input, char **envp)
{	
	char	**tab_paths;
	char	*exec_path;

	if (!envp)
		return (NULL);
	tab_paths = get_path(envp);
	if (!tab_paths)
		return (NULL);
	exec_path = check_exec_path(tab_paths, input);
	if (!exec_path)
	{
		free_split(tab_paths);
		return (NULL);
	}
	free_split(tab_paths);
	return (exec_path);
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
