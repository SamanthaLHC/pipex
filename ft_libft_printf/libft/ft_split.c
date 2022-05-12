/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:06:49 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/20 12:33:41 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static int	ft_count(char const *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != sep) && (i == 0 || s[i - 1] == sep))
			count ++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		start;

	i = 0;
	j = 0;
	tab = malloc (sizeof(*tab) * (ft_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (j < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		i++;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_substr(s, start, i - start);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
/*
#include <stdio.h>
int main()
{	
    char *s = "coucoucava";
    char sep = 'k';
    char **tab = ft_split(s, sep);
    int j = 0;
    while (tab[j])
    {
        printf("%s\n", tab[j]);
        j++;
    }

	char *s1 = "kkkcoucoukkcakkvakk";
    char sep1 = 'k';
    char **tab1 = ft_split(s1, sep1);
    int i = 0;
    while (tab1[i])
    {
        printf("%s\n", tab1[i]);
        i++;
    }

	char *s2 = "coucoukkcakkvakk";
    char sep2 = 'k';
    char **tab2 = ft_split(s2, sep2);
    int k = 0;
    while (tab2[k])
    {
        printf("%s\n", tab2[k]);
        k++;
    }

	char *s3 = "coucoukkcakkva";
    char sep3 = 'k';
    char **tab3 = ft_split(s3, sep3);
    int l = 0;
    while (tab3[l])
    {
        printf("%s\n", tab3[l]);
        l++;
    }

	char *s5 = "kkkkk";
    char sep5 = 'k';
    char **tab5 = ft_split(s5, sep5);
    int o = 0;
    while (tab5[o])
    {
        printf("%s\n", tab5[o]);
        o++;
    }
	if (tab5[0] == NULL)
		printf("NULL\n");

	char *s4 = "";
    char sep4 = 'k';
    char **tab4 = ft_split(s4, sep4);
    int m = 0;
    while (tab4[m])
    {
        printf("%s\n", tab4[m]);
        m++;
    }
	if (tab4[0] == NULL)
		printf("NULL\n");
}
*/
