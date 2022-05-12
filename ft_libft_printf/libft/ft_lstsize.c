/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:32:56 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:31:06 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
#include <stdio.h>
int main()
{

	struct s_list elem1;
	struct s_list elem2;
	struct s_list elem3;
	struct s_list elem4;
	struct s_list elem5;
	struct s_list *lst;

	lst = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = &elem5;
	elem5.next = NULL;
	
	printf("%d\n", ft_lstsize(lst));
}
*/
