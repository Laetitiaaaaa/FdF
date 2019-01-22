/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:15:51 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/21 15:38:13 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		taillen;

	i = 0;
	taillen = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		if (haystack[i] == needle[0] && (taillen + i) <= len)
		{
			if (ft_strncmp(&haystack[i], &needle[0], taillen) == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
