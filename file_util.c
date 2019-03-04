/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:07:51 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/04 13:17:55 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int key, t_my_m *m)
{
	(key == PLUS) ? ft_zoom(&m->lst_point, m, 2) : 0;
	(key == M) ? ft_zoom(&m->lst_point, m, 0.5) : 0;
	(key == F_H) ? (m->offy -= 10) : 0;
	(key == F_B) ? (m->offy += 10) : 0;
	(key == F_G) ? (m->offx -= 10) : 0;
	(key == F_D) ? (m->offx += 10) : 0;
	(key == TWO) ? ft_rotation_x(10, m) : 0;
	(key == FIVE) ? ft_rotation_x(-10, m) : 0;
	(key == FOUR) ? ft_rotation_y(10, m) : 0;
	(key == SIX) ? ft_rotation_y(-10, m) : 0;
	(key == ONE) ? ft_rotation_z(10, m) : 0;
	(key == THREE) ? ft_rotation_z(-10, m) : 0;
	(key == P) ? ft_perspective(m) : 0;
	(key == ESC) ? ft_free(m) : 0;
	ft_always(m);
	return (1);
}

void	ft_free(t_my_m *m)
{
	t_v3 *keep;

	while (m->lst_point != NULL)
	{
		keep = m->lst_point;
		m->lst_point = m->lst_point->next;
		free(keep);
	}
	close(m->fd);
	exit(0);
}

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

void	ft_perspective(t_my_m *m)
{
	t_v3	*keep;

	keep = m->lst_point;
	while (keep != NULL)
	{
		keep->point.x = keep->origin.x + 0.71 * keep->origin.z;
		keep->point.y = keep->origin.y + 0.71 * keep->origin.z;
		keep->point.z = keep->origin.z;
		keep = keep->next;
	}
}
