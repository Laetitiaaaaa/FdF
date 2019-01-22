/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:40:16 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/23 11:09:15 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	size_t i;

	if (alst != 0)
	{
		i = (*alst)->content_size;
		while ((*alst) != NULL)
		{
			del((*alst)->content, i);
			free((*alst));
			(*alst) = (*alst)->next;
		}
	}
	(*alst) = NULL;
}
