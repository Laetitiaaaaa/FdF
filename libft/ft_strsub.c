/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:58:14 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/04 11:20:18 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*tab;

	if (s == 0)
		return (NULL);
	i = 0;
	j = 0;
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] != 0 && i != start)
		i++;
	if (i == start)
	{
		while (j < len)
		{
			tab[j] = s[i];
			i++;
			j++;
		}
		tab[j] = 0;
	}
	return (tab);
}
