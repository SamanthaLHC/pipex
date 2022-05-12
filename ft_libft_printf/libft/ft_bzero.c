/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:21:46 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:28:19 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{	
		str[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
char str[] = "pwetpwetpwetpwet";
char str1[] = "pwetpwetpwetpwet";
size_t n = 6;
ft_bzero(str, n);
printf("ft_bzero: %s", str);
bzero(str1, n);
printf("\nbzero: %s\n", str1);
}
*/
