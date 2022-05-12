/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:26:46 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:31:51 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	char			*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst = dest;
	s = (char *)src;
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
char sc[] = "wowo";
char sc1[] = "wowo";
char dst[] = "....";
char test[] = "....";
size_t n = 4; 
void *sh;
ft_memcpy(dst, sc, n);
printf("ft_memcpy: %s", dst);
memcpy(test, sc1, n);
printf("\nmemcpy: %s", test);
sh = ft_memcpy(NULL, NULL, 4);
printf("ft_memcpy avec null both param:%p\n", sh);
}
*/
