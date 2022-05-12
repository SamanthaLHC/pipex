/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:28:36 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:19:59 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	if (n == 0)
		count ++;
	while (n != 0)
	{	
		n /= 10;
		count ++;
	}
	return (count);
}

static void	ft_conv(int n, int i, char *str)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
	}
	if ((nb > 9) || (n < 0))
		ft_conv(nb / 10, i - 1, str);
	str[i] = nb % 10 + '0';
}

char	*ft_itoa(int n)
{
	char			*str_nb;
	long int		i;

	i = ft_count(n);
	str_nb = (char *) malloc(sizeof (char) * i + 1);
	if (!str_nb)
		return (0);
	ft_conv(n, i - 1, str_nb);
	str_nb[i] = '\0';
	if (n < 0)
	{
		str_nb[0] = '-';
	}
	return (str_nb);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac == 2) {
		printf("%s\n", ft_itoa(atoi(av[1])));
	}
}
*/
