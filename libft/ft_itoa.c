/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 07:58:14 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/21 12:43:32 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sizen(int n)
{
	int c;

	c = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			c = 11;
			return (c);
		}
		c++;
		n = -n;
	}
	if (n == 0)
		c = 1;
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static char		*ft_putlim(char *tab, int n)
{
	int i;
	int j;

	i = ft_sizen(n);
	j = i - 1;
	tab[0] = '-';
	tab[1] = '2';
	n = 147483648;
	while (n > 0)
	{
		tab[j--] = (n % 10) + '0';
		n = n / 10;
	}
	tab[i] = 0;
	return (tab);
}

char			*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		j;

	i = ft_sizen(n);
	j = i - 1;
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
			return (tab = ft_putlim(tab, n));
		tab[0] = '-';
		n = -n;
	}
	if (n == 0)
		tab[j] = '0';
	while (n > 0)
	{
		tab[j--] = (n % 10) + '0';
		n = n / 10;
	}
	tab[i] = 0;
	return (tab);
}
