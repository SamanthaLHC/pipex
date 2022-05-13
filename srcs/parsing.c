/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:50:04 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/13 17:22:23 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd()
{
	// open les files pour avoir les fd
	// mettre les fd dans un tab ?
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