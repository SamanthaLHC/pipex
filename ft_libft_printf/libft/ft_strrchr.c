/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:19:45 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:36:17 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s;
	s1 += ft_strlen(s1);
	while (s1 >= s)
	{
		if (*s1 == (char)c)
			return (s1);
		else
			s1--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char    *s = "koyotte";
	int c = 't';
	int e = 'p';
	int k = '\0';
	char  *test;
	test = (ft_strrchr(s, c));
	printf("my ft_: %s", test);
	test = (strrchr(s, c));
	printf("\nstrrchr: %s", test);
	test = (ft_strrchr(s, e));
    printf("\nmy ft_: %s", test);
    test = (strrchr(s, e));
    printf("\nstrrchr: %s", test);
	test = (ft_strrchr(s, k));
	printf("\nmy ft_: %s", test);
	test = (strrchr(s, k));
	printf("\nstrrchr: %s", test);
}
*/
