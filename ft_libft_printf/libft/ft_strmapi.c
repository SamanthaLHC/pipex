/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:32:13 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:35:32 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*new_str;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new_str)
		return (0);
	while (str[i])
	{
		new_str[i] = f(i, str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
#include <stdio.h>
#include "libft.h"

char tatatoto(unsigned int i, char c)
{
(void)i;
return (char)ft_toupper(c);
}
int main()
{
char	*src;
char	(*f)(unsigned int, char);


f = &tatatoto;
src = "random pouet toupper";
printf("%s\n", src);
printf("toupper=%s\n", ft_strmapi(src, f));

return (0);
}
*/
