/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:32:27 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:30:38 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
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
	
	printf("%p\n", lst);
	printf("%p\n", elem4.next);
	printf("%p\n", ft_lstlast(lst));
}
*/
