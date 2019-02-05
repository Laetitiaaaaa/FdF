/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:12:05 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/05 10:46:40 by llejeune         ###   ########.fr       */
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
	t_split		my;
	char		**tab;

	if (s == 0)
		return (NULL);
	my.i = 0;
	my.j = 0;
	my.a = ft_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * my.a)))
		return (NULL);
	while (s[my.i] != 0 && my.j < my.a)
	{
		while (s[my.i] == c)
			my.i++;
		tab[my.j] = ft_strsub(s, (unsigned int)my.i, ft_lenword(s, my.i, c));
		my.i = my.i + ft_lenword(s, my.i, c);
		my.j++;
	}
	tab[my.j] = NULL;
	return (tab);
}
