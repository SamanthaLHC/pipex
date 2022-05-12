/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:27:26 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:32:32 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	conv_c;
	unsigned char	*str;

	i = 0;
	conv_c = (unsigned char)c;
	str = s;
	while (i < n)
	{
		str[i] = conv_c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
int c = '!';
char str[] = "wowowowowowowowo";
char str1[] = "wowowowowowowowo";
size_t n = 3; 
ft_memset(str, c, n);
printf("ft_memset: %s", str);
memset(str1, c, n);
printf("\nmemset: %s\n", str1);
}
*/
