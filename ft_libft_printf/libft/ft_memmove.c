/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:38:26 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:32:09 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst = dest;
	s = (unsigned char *) src;
	if (s < dst)
	{
		while (n > 0)
		{
			dst[n - 1] = s[n - 1];
			n--;
		}
		return (dest);
	}
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
char s[] = "abcdefghijklmn";
char s2[] = "abcdefghijklmn";
size_t n = 4; 
// (source + 1 = dst)
ft_memmove(s + 1, s, n);
printf("ft_memmove: %s", s);
memmove(s2 + 1, s2, n);
printf("\nmemmove: %s", s2);
}
 */
