/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:50:39 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:34:25 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{	
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
#include "libft.h"

void tatatoto(unsigned int i, char *c)
{
	(void)i;
	ft_toupper(*c);
	ft_putchar_fd(*c, 1);
}

int main()
{
	char	*src;
	void	(*f)(unsigned int, char*);


	f = &tatatoto;
	src = "random pouet toupper";
	ft_striteri(src, f);

	return (0);
}
*/
