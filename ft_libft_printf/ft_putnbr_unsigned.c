/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:38:43 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/20 13:13:29 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cont(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count ++;
	while (n != 0)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (ft_cont(n));
}
