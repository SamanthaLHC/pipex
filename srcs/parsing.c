/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:50:04 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/18 14:29:25 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(char **input)
{
	int	fd1;
	int	fd2;

	fd1 = open(input[1], O_RDONLY);
	fd2 = open(input[4], O_WRONLY | O_CREAT | O_TRUNC, 644);
	// open les files pour avoir les fd
	// mettre les fd dans un ta  b ?
	// gestion d erreur sii le fichier 1 n existe pas ou si le files 
	//ou si le file2 a deja des droits (autre que 644)
	
}

char	**get_path()
{
	//parcourir env pour recup path avec strcmp
	//split tous les  : pour recuperer dans un tab de tab les segments des differents path
	// retourner ce tab
}

char	*exec_cmd()
{
	//parcourir le tableau de paths possible jusqua tomber sur cellui compatib le avec la cmd
	//concat avec / le path et la cmd
	// return la ligne de cmd executable
}