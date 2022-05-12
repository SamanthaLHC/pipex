/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:19:06 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:36:02 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*bbig;
	int		tmp;

	i = 0;
	bbig = (char *)big;
	if (((char *)little)[0] == '\0')
		return (bbig);
	while (i < len && bbig[i] != '\0')
	{
		tmp = i;
		j = 0;
		while (((char *)little)[j]
				&& (bbig[i] == ((char *)little)[j]) && (i < len))
		{	
			i++;
			j++;
		}
		if (((char *)little)[j] == '\0')
			return (&bbig[tmp]);
		i = tmp;
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char *big = "wewewer";
	char *little = "wewer";
	char *lit = "ewe";
	char *litv = "";
	char *test;
	test = (strnstr(big, little, 3));
	printf("strnstr: %s\n", test);
	test = (ft_strnstr(big, little, 3));
	printf("ft__: %s\n", test);

	test = (strnstr(big, little, 9));
	printf("strnstr: %s\n", test);
	test = (ft_strnstr(big, little, 9));
	printf("ft__: %s\n", test);

	test = (strnstr(big, lit, 5));
	printf("strnstr: %s\n", test);
	test = (ft_strnstr(big, lit, 5));
	printf("ft__: %s\n", test);

	test = (strnstr(big, litv, 3));
	printf("strnstr: %s\n", test);
	test = (ft_strnstr(big, litv, 3));
	printf("ft__: %s\n", test);
}
*/
