/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:08:46 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/03 10:18:17 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (i == n)
		return (0);
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]) && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
char a[]="t";
char b[]="zephyr";
char c[]="";
char d[]="kokolekoyotte";
char e[]="aaabbb";
char f[]="aaaa";
printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",
	    strncmp(a, b, 2), ft_strncmp(a, b, 2), 
		strncmp(a, c, 1), ft_strncmp(a, c, 1),
		strncmp(b, d, 5), ft_strncmp(b, d, 5), 
		strncmp(a, a, 2), ft_strncmp(a, a, 2),
	    strncmp(e, f, 3), ft_strncmp(e, f, 3));
return (0);
}
*/
