/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:39:34 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/15 12:04:27 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*s2;
	char	*s3;

	i = 0;
	s2 = (char *)s1;
	j = ft_strlen(s2) - 1;
	while ((s2[i]) && (ft_strchr(set, s2[i])))
	{
		i++;
	}
	while ((j >= 0) && (ft_strchr(set, s2[j])))
	{
		j--;
	}
	if (j < i)
	{
		s2 = ft_calloc(1, 1);
		return (s2);
	}
	len = j - i + 1;
	s3 = ft_substr(s2, i, len);
	return (s3);
}
/*
#include <stdio.h>
#include "libft.h"
int main ()
{
	char *s1 = "blablabl"; 
	char *set = "bl";
	printf("%s\n",ft_strtrim(s1, set));

	char *s2 = "blabla"; 
	char *set1 = "bl";
	printf("%s\n",ft_strtrim(s2, set1));


	char *s3 = "ablabl"; 
	char *set2 = "bl";
	printf("%s\n",ft_strtrim(s3, set2));
}
*/
