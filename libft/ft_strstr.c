/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:31:20 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/21 15:31:26 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int len;
	int	j;

	len = ft_strlen(needle);
	j = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (haystack[j] != 0)
	{
		if (haystack[j] == needle[0])
		{
			if (ft_strncmp(&haystack[j], &needle[0], len) == 0)
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (NULL);
}
