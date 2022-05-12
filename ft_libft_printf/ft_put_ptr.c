/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:49:59 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/20 13:15:29 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(unsigned long int n)
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

static void	ft_put_hexa(unsigned long int n)
{
	char	*base_hexa;

	base_hexa = "0123456789abcdef";
	if (n > 15)
		ft_put_hexa(n / 16);
	ft_putchar_fd(base_hexa[n % 16], 1);
}

int	ft_put_ptr(unsigned long int n)
{
	ft_putstr_fd("0x", 1);
	ft_put_hexa(n);
	return (ft_cnt(n) + 2);
}
