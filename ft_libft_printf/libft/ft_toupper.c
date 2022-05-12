/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:44:07 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:37:17 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	else
		return (c);
}

/*
#include <stdio.h>
int main()
{
	int c = 'w';
	c = ft_toupper(c);
	printf("ft_toupper is like: %c", c);
}
*/
