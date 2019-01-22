/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:13:12 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/15 11:44:59 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*tab;

	i = 0;
	tab = malloc(size);
	if (tab == 0)
		return (NULL);
	while (i < size)
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}
