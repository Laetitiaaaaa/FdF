/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:57:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/25 14:58:10 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v3	*ft_new_node(t_v3 *new_node)
{
	if (!(new_node = malloc(sizeof(t_v3))))
		return (0);
	new_node->point.x = 0;
	new_node->point.y = 0;
	new_node->point.z = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_node(t_v3 **alst, t_v3 *new_node)
{
	t_v3	*keep;

	keep = (*alst);
	if (keep != NULL && new_node != NULL)
	{
		while (keep->next != NULL)
			keep = keep->next;
		keep->next = new_node;
	}
	if ((*alst) == NULL)
		(*alst) = new_node;
}

