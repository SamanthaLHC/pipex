/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:38:25 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/20 13:14:13 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count ++;
	while (n != 0)
	{
		n /= 16;
		count ++;
	}
	return (count);
}

int	ft_putnbr_hexa(unsigned int n)
{
	char	*base_hexa;

	base_hexa = "0123456789abcdef";
	if (n > 15)
		ft_putnbr_hexa(n / 16);
	ft_putchar_fd(base_hexa[n % 16], 1);
	return (ft_count(n));
}
