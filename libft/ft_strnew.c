/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:35:02 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/20 13:47:44 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (tab == 0)
		return (NULL);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
