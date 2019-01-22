/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:23:27 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/23 16:30:14 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[len]);
	while (len > 0)
	{
		if (s[len] == c)
			return ((char *)&s[len]);
		len--;
	}
	if (s[0] == c)
		return ((char *)&s[0]);
	return (NULL);
}
