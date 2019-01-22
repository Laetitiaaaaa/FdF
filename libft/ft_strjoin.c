/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:18:38 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/14 11:13:07 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;
	int		k;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	k = 0;
	while (s1[j] != 0)
		tab[k++] = ((char *)s1)[j++];
	j = 0;
	while (s2[j] != 0)
		tab[k++] = ((char *)s2)[j++];
	tab[k] = ((char *)s2)[j];
	return (tab);
}
