/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:10:15 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:25:48 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	conv_c;
	char			*str;

	i = 0;
	conv_c = (unsigned char)c;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)(str[i]) == conv_c)
			return (str + i);
		i++;
	}
	return (NULL);
}	
/*
#include <stdio.h>
#include <string.h>
int main()	
{
	char *test;
	char *s = "pow pow things";
	size_t n = 7;
	int c = 'w';
	int d = 't';
	int e = 'a';
	int f = '\0';
	test = (ft_memchr(s, c, n));
	printf("my ft_: %s", test);
	test = (memchr(s, c, n));
	printf("\nmemchr: %s\n", test);
	test = (ft_memchr(s, d, n));
	printf("\nmy ft_: %s", test);
	test = (memchr(s, d, n));
	printf("\nmemchr: %s\n", test);
	test = (ft_memchr(s, e, n));
	printf("\nmy ft_: %s", test);
	test = (memchr(s, e, n));
	printf("\nmemchr: %s\n", test);
	test = (ft_memchr(s, f, n));
	printf("\nmy ft_: %s", test);
	test = (memchr(s, f, n));
	printf("\nmemchr: %s", test);
}
*/
