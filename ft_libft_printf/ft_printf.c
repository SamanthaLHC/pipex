/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:39:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/20 13:13:50 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

static int	ft_put_smth(va_list arg, const char *format)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	{	
		if (format[i] == 'c')
			len = ft_putchar(va_arg(arg, int));
		else if (format[i] == 's')
			len = ft_putstr(va_arg(arg, char *));
		else if (format[i] == 'p')
			len = ft_put_ptr(va_arg(arg, unsigned long int));
		else if ((format[i] == 'd') || (format[i] == 'i'))
			len = ft_putnbr(va_arg(arg, int));
		else if (format[i] == 'u')
			len = ft_putnbr_unsigned(va_arg(arg, unsigned int));
		else if (format[i] == 'x')
			len = ft_putnbr_hexa(va_arg(arg, unsigned int));
		else if (format[i] == 'X')
			len = ft_putnbr_hexa_upp(va_arg(arg, unsigned int));
		else if (format[i] == '%')
			len = ft_putchar('%');
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start (arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{	
		if (format[i] != '%')
			len += ft_putchar(format[i]);
		if (format[i] == '%')
		{
			len += ft_put_smth(arg, &format[i + 1]);
			i++;
		}
		i++;
	}
	va_end (arg);
	return (len);
}
