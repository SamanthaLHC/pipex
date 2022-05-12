/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:29:32 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:29:37 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (*alst == NULL)
	{
		*alst = new;
	}	
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
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
	struct s_list new;

	lst = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = &elem5;
	elem5.next = NULL;

	printf("%p\n", lst);
	printf("%p\n", elem4.next);
	printf("%p\n", ft_lstlast(lst));
	printf("%d\n", ft_lstsize(lst));
	ft_lstadd_back(&lst, &new);
	printf("%p\n", ft_lstlast(lst));
	printf("%d\n", ft_lstsize(lst));
}
*/
