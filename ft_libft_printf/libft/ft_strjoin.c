/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:40:08 by sle-huec          #+#    #+#             */
/*   Updated: 2022/06/04 00:00:22 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char const *s3)
{
	char		*new_str;
	size_t		size;

	size = (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	new_str = (char *)malloc(sizeof(char) * size);
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, s1, size);
	ft_strlcat((char *)new_str, s2, size);
	ft_strlcat((char *)new_str, s3, size);
	return (new_str);
}
