/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:41:59 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/21 11:28:41 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wint(const char *s, int i)
{
	if (s[i] == 32 || s[i] == '\t' || s[i] == '\n')
	{
		while (s[i] == 32 || s[i] == '\t' || s[i] == '\n')
			i++;
	}
	else
		i = 0;
	return (i);
}

static int	ft_sizes(int i, int a)
{
	int	s;

	s = 0;
	while (i++ < a)
		s++;
	return (s);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		a;
	char	*tab;

	if (s == 0)
		return (NULL);
	j = 0;
	a = ft_strlen(s);
	i = ft_wint(s, 0);
	if (s[a - 1] == 32 || s[a - 1] == '\t' || s[a - 1] == '\n')
	{
		while (s[a - 1] == 32 || s[a - 1] == '\t' || s[a - 1] == '\n')
			a--;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (ft_sizes(i, a) + 1))))
		return (NULL);
	while (i < a)
		tab[j++] = ((char *)s)[i++];
	tab[j] = 0;
	return (tab);
}
