/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:16:42 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/08 11:48:25 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*sc;
	size_t	tmp;

	i = 0;
	j = 0;
	sc = (char *)src;
	tmp = ft_strlen(dst);
	if (tmp >= size)
		return (size + ft_strlen(sc));
	while (dst[i])
		i++;
	while (sc[j] != '\0' && i < size - 1)
	{
		dst[i] = sc[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (tmp + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int    main(void)
{
	char src[]="nounou";
	char dest1[20]="salut";
	char sc[]="nounou";
	char dest2[20]="salut";
	printf("%lu\n", ft_strlcat(dest1, src,7));
	printf("%lu\n", strlcat(dest2, sc, 7));
	return (0);
}
*/
