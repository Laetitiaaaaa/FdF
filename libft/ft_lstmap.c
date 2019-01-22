/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:50:32 by llejeune          #+#    #+#             */
/*   Updated: 2018/11/23 16:04:41 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (lst == 0)
		return (NULL);
	else
	{
		if (!(tmp = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		tmp = f(lst);
		tmp->next = ft_lstmap(lst->next, f);
	}
	return (tmp);
}
