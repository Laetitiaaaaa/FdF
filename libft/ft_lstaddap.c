/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:21:43 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/23 16:05:18 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddap(t_list **alst, t_list *new)
{
	while ((*alst)->next != NULL)
	{
		(*alst) = (*alst)->next;
	}
	(*alst)->next = new;
	new->next = NULL;
}
