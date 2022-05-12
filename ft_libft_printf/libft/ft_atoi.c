/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:23:25 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/20 18:34:16 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FT_INT_MAX 2147483647
#define FT_INT_MIN -2147483648

int	ft_is_int(long int *result, char c, int neg_or_pos)
{
	int	limit;
	int	quotien;
	int	remainder;

	limit = FT_INT_MAX;
	if (neg_or_pos < 0)
		limit = FT_INT_MIN;
	quotien = limit / 10 * neg_or_pos;
	remainder = limit % 10 * neg_or_pos;
	if ((*result > quotien)
		|| ((*result == quotien) && (c - '0') > remainder))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	*result = *result * 10 + c - '0';
	return (0);
}

int	check_pars(char *str, int i, int neg_or_pos, int *err)
{
	long int	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_is_int(&result, str[i], neg_or_pos) == -1)
		{
			*err = -1;
			break ;
		}
		i++;
	}
	return (result * neg_or_pos);
}

int	ft_atoi(const char *nptr, int *err)
{
	int		i;
	int		neg_or_pos;
	char	*str;

	str = (char *)nptr;
	i = 0;
	neg_or_pos = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_or_pos = -neg_or_pos;
		i++;
	}
	return (check_pars(str, i, neg_or_pos, err));
}
/*
#include <stdlib.h>
#include <stdio.h>
int main()
{
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n
	%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
			atoi("-2"),
			ft_atoi("-2"),
			atoi("g678"),
			ft_atoi("g678"),
			atoi("   4"),
			ft_atoi("   4"),
			atoi(" 56"),
			ft_atoi(" 56"),
			atoi("+56jihyuyr"),
			ft_atoi("+56jihyuyr"),
			atoi("iuioyouy"),
			ft_atoi("iuioyouy"),
			atoi("2147483647"),
			ft_atoi("2147483647"),
			atoi("2147483648"),
			ft_atoi("2147483648"),
			atoi("-2147483648"),
			ft_atoi("-2147483648"),
			atoi("0"),
			ft_atoi("0"),
			atoi(""),
			ft_atoi(""),
			atoi("                78"),
			ft_atoi("                78"),
			atoi("++2"),
			ft_atoi("++2"),
			atoi("--2"),
			ft_atoi("--2"));
}
*/
