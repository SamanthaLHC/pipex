/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:16:42 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/01 14:04:39 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*dest;
	char	*s1;

	len = 0;
	i = 0;
	s1 = (char *)src;
	while (s1[len])
	{
		len++;
	}
	dest = malloc(sizeof (char) * (len + 1));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
	printf("%s\n", ft_strdup(argv[1]));
	printf("%s\n", strdup(argv[1]));
	}
	return (0);
}
*/
