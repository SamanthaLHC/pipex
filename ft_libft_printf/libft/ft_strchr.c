/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:16:42 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/08 15:56:54 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == 0 && c == 0)
		return (i);
	return (-1);
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
