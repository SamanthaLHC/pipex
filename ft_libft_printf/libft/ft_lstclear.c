/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:31:09 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 11:31:13 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*mv;
	t_list	*i;

	mv = *lst;
	while (mv)
	{
		del(mv->content);
		i = mv->next;
		free(mv);
		mv = i;
	}
	*lst = NULL;
}
