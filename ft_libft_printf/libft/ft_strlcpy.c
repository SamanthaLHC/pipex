/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:26:44 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/09 14:34:23 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{	
		while ((src[i]) && (i < dstsize - 1))
		{	
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
char    *src1 = "yo";
char    dst1[11];
char    dst2[11];

printf("n = 4 : %lu \n", ft_strlcpy(dst1, src1, 3));
printf("strlcpy : %lu \n", strlcpy(dst1, src1, 3));
printf("n = 9 : %lu \n", ft_strlcpy(dst2, src1, 11));
printf("strlcpy : %lu \n", strlcpy(dst2, src1, 11));

}
*/
