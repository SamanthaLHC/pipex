/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_upp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:36:23 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/20 13:14:32 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ct(unsigned int n)
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

int	ft_putnbr_hexa_upp(unsigned int n)
{
	char	*base_hexa;

	base_hexa = "0123456789ABCDEF";
	if (n > 15)
		ft_putnbr_hexa_upp(n / 16);
	ft_putchar_fd(base_hexa[n % 16], 1);
	return (ft_ct(n));
}
