/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:05:02 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/25 15:15:28 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_v3 **lst_point, my_m *m, mat *s, float i)
{
	t_v3 *keep;

	keep = (*lst_point);
	while (keep != NULL)
	{
		keep->point.x = keep->point.x * i;
		keep->point.y = keep->point.y * i;
		keep->point.z = keep->point.z * i;
		keep = keep->next;
	}
	ft_always(m);
}

