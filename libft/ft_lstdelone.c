/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:21:22 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/23 10:44:01 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	size_t i;

	if (alst != 0)
	{
		i = (*alst)->content_size;
		del((*alst)->content, i);
		free((*alst));
		(*alst) = NULL;
	}
}
