/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:16:42 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:33:54 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s;
	while (*s1)
	{
		if (*s1 == (char)c)
			return (s1);
		s1++;
	}
	if (*s1 == 0 && (char)c == 0)
		return (s1);
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
	test = (ft_strchr(s, c));
	printf("my ft_: %s", test);
	test = (strchr(s, c));
	printf("\nstrchr: %s", test);
	test = (ft_strchr(s, e));
	printf("\nmy ft_: %s", test);
	test = (strchr(s, e));
	printf("\nstrchr: %s", test);
	test = (ft_strchr(s, k));
	printf("\nmy ft_: %s", test);
	test = (strchr(s, k));
	printf("\nstrchr: %s", test);
}
*/
