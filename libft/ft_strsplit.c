/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:12:05 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/21 12:02:09 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word(const char *s, char c)
{
	int i;
	int	word;
	int	check;

	i = 0;
	word = 0;
	check = 1;
	while (s[i] != 0)
	{
		if (s[i] != c && check == 1)
		{
			check = 0;
			word++;
		}
		if (s[i] == c)
			check = 1;
		i++;
	}
	return (word);
}

static int		ft_lenword(const char *s, int i, char c)
{
	int k;

	k = 0;
	while (s[i] != c && s[i] != 0)
	{
		i++;
		k++;
	}
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		a;
	char	**tab;

	if (s == 0)
		return (NULL);
	i = 0;
	j = 0;
	a = ft_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (a + 1))))
		return (NULL);
	while (s[i] != 0 && j < a)
	{
		while (s[i] == c)
			i++;
		tab[j++] = ft_strsub(s, (unsigned int)i, ft_lenword(s, i, c));
		i = i + ft_lenword(s, i, c);
	}
	tab[j] = NULL;
	return (tab);
}
